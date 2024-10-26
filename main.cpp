// main.cpp

#include <stdio.h>             // Standard Input/Output library for printf and file handling
#include <GL/glew.h>           // GLEW library for managing OpenGL extensions
#include <GLFW/glfw3.h>        // GLFW library for handling window and OpenGL context
#include <stdlib.h>            // Standard library for general functions like malloc, rand, etc.
#include <math.h>              // Math library for mathematical functions
#include <string>              // For std::string
#include "imgui_wrapper.h"     // Header file for the ImGui wrapper

#define STB_IMAGE_IMPLEMENTATION // Required for stb_image
#include "stb_image.h"           // stb_image for texture loading

#include <SDL2/SDL.h>            // SDL2 for audio
#include <SDL2/SDL_mixer.h>      // SDL_mixer for audio mixing

#include <chrono>                // For high-resolution clock (optional)

#define MAX_PARTICLES 3000             // Maximum number of particles in the simulation
#define EXPLOSION_PARTICLES 30         // Number of particles created in an explosion

// Structure to represent a particle in the simulation
typedef struct {
    float x, y;            // Position of the particle
    float speedX, speedY;  // Speed of the particle
    float r, g, b, a;      // Color (RGB) and alpha (opacity)
    float size;            // Size of the particle
    float life;            // Remaining life of the particle
    int canExplode;        // Flag to indicate if this particle can explode
    int exploding;         // Flag to indicate if this particle is exploding
} Particle;

Particle particles[MAX_PARTICLES]; // Array to store all particles

// Adjustable parameters controlled via ImGui
int maxParticles = 1000;             // Default to 1000 particles
int explosionChance = 1;             // Default explosion chance (%)
float minSize = 10.0f;               // Minimum particle size
float maxSize = 100.0f;              // Maximum particle size
float explosionMinSize = 5.0f;       // Minimum size for explosion particles
float explosionMaxSize = 15.0f;      // Maximum size for explosion particles
float minLife = 0.05f;               // Minimum particle life
float maxLife = 1.2f;                // Maximum particle life
float minSpeedX = -0.05f;            // Minimum speedX
float maxSpeedX = 0.05f;             // Maximum speedX
float minSpeedY = 0.1f;              // Minimum speedY
float maxSpeedY = 0.15f;             // Maximum speedY
float baseColor[3] = {1.0f, 0.5f, 0.0f}; // Base color (Yellowish)

// Volume Control Variable
float musicVolume = 0.2f; // Volume: 0.0 (mute) to 1.0 (max)

// Pomodoro Timer Variables
enum TimerState { STOPPED, RUNNING, PAUSED };
TimerState timerState = STOPPED;
float timerDuration = 1500.0f; // Default 25 minutes in seconds
float timerRemaining = 1500.0f;
bool timerFinished = false;

// Shader program ID
GLuint shaderProgram;

// VAO and VBO IDs
GLuint VAO, VBO;

// Texture ID
GLuint particleTexture;

// Uniform locations
GLint useTextureLocation;
GLint particleTextureLocation;

// Audio Assets
Mix_Music* bgm = NULL;                    // Background music
Mix_Chunk* clickSound = NULL;             // Sound effect for mouse clicks
Mix_Chunk* clickClockSound = NULL;        // Sound effect for Pomodoro button clicks
Mix_Chunk* startSound = NULL;             // Sound when timer starts
Mix_Chunk* finishCountdownSound = NULL;   // Sound when timer finishes

// Function to check and print OpenGL errors
void checkOpenGLError(const char* stmt, const char* fname, int line) {
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        printf("OpenGL error 0x%X, at %s:%i - for %s\n", err, fname, line, stmt);
        // Optionally, exit or handle the error
    }
}

#define GL_CHECK(stmt) do { \
        stmt; \
        checkOpenGLError(#stmt, __FILE__, __LINE__); \
    } while (0)

// Function to compile shaders and link shader program
GLuint compileShaders(const char* vertexSource, const char* fragmentSource) {
    // Compile Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    // Check for compile errors
    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    // Compile Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }

    // Link Shaders into Shader Program
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "color");
    glBindAttribLocation(program, 2, "pointSize");
    glLinkProgram(program);
    // Check for linking errors
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }

    // Delete shaders as they're linked into program now and no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

// Function to load texture using stb_image
GLuint loadTexture(const char* filepath) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (!data) {
        printf("Failed to load texture: %s\n", filepath);
        return 0;
    }

    GLuint texture;
    GL_CHECK(glGenTextures(1, &texture));
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, texture));

    // Set texture parameters
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    // Determine image format with default
    GLenum format = GL_RGB; // Default format
    if (nrChannels == 1)
        format = GL_RED;
    else if (nrChannels == 3)
        format = GL_RGB;
    else if (nrChannels == 4)
        format = GL_RGBA;
    else {
        printf("Unsupported number of channels (%d) in texture: %s. Using GL_RGB as default.\n", nrChannels, filepath);
    }

    // Upload the texture data
    GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data));
    GL_CHECK(glGenerateMipmap(GL_TEXTURE_2D));

    stbi_image_free(data); // Free image memory
    return texture;
}

// Function to initialize SDL2 and SDL_mixer for audio
bool initAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialize SDL_mixer with desired audio format
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

// Function to load audio assets
bool loadAudio() {
    // Load background music
    bgm = Mix_LoadMUS("assets/synthwave_bgm.mp3");
    if (!bgm) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    // Load sound effects
    clickSound = Mix_LoadWAV("assets/click.wav");
    if (!clickSound) {
        printf("Failed to load click sound! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    // Load Pomodoro sound effects
    clickClockSound = Mix_LoadWAV("assets/clickClock.wav");
    if (!clickClockSound) {
        printf("Failed to load clickClock sound! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    startSound = Mix_LoadWAV("assets/startSound.wav");
    if (!startSound) {
        printf("Failed to load startSound! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    finishCountdownSound = Mix_LoadWAV("assets/finishCountdown.wav");
    if (!finishCountdownSound) {
        printf("Failed to load finishCountdown sound! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

// Function to play background music
void playBackgroundMusic() {
    if (Mix_PlayMusic(bgm, -1) == -1) { // -1 for infinite loop
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
    }
}

// Function to play click sound
void playClickSound() {
    if (Mix_PlayChannel(-1, clickSound, 0) == -1) { // -1 for first available channel
        printf("Mix_PlayChannel (Click): %s\n", Mix_GetError());
    }
}

// Function to play Pomodoro button click sound
void playClickClockSound() {
    if (Mix_PlayChannel(-1, clickClockSound, 0) == -1) { // -1 for first available channel
        printf("Mix_PlayChannel (ClickClock): %s\n", Mix_GetError());
    }
}

// Function to play start timer sound
void playStartSound() {
    if (Mix_PlayChannel(-1, startSound, 0) == -1) { // -1 for first available channel
        printf("Mix_PlayChannel (Start): %s\n", Mix_GetError());
    }
}

// Function to play finish countdown sound
void playFinishCountdownSound() {
    if (Mix_PlayChannel(-1, finishCountdownSound, 0) == -1) { // -1 for first available channel
        printf("Mix_PlayChannel (FinishCountdown): %s\n", Mix_GetError());
    }
}

// Function to initialize shaders, VAO, and VBO
void initRendering() {
    // Initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        printf("Error initializing GLEW: %s\n", glewGetErrorString(err));
        return;
    }

    // Enable program point size to allow the shader to set gl_PointSize
    GL_CHECK(glEnable(GL_PROGRAM_POINT_SIZE));

    // Enable blending for transparency (optional but recommended)
    GL_CHECK(glEnable(GL_BLEND));
    GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    // Define shader source code with texture sampling
    const char* vertexSource = R"(
    #version 150 core
    in vec2 position;
    in vec4 color;
    in float pointSize;

    out vec4 fragColor;

    void main()
    {
        fragColor = color;
        gl_Position = vec4(position, 0.0, 1.0);
        gl_PointSize = pointSize;
    }
    )";

    // Modified Fragment Shader to use texture conditionally
    const char* fragmentSource = R"(
    #version 150 core
    in vec4 fragColor;
    out vec4 outColor;

    uniform sampler2D particleTexture; // Sampler uniform
    uniform bool useTexture;           // Uniform to toggle texture usage

    void main()
    {
        if (useTexture) {
            // Sample the texture using gl_PointCoord
            vec4 texColor = texture(particleTexture, gl_PointCoord);
            if (texColor.a < 0.1)
                discard; // Discard transparent fragments for better performance

            outColor = fragColor * texColor; // Apply texture color
        }
        else {
            // Draw circular particles
            float dist = length(gl_PointCoord - vec2(0.5));
            if (dist > 0.5)
                discard;
            outColor = fragColor;
        }
    }
    )";

    // Compile and link shaders
    shaderProgram = compileShaders(vertexSource, fragmentSource);

    // Generate and bind VAO
    GL_CHECK(glGenVertexArrays(1, &VAO));
    GL_CHECK(glBindVertexArray(VAO));

    // Generate and bind VBO
    GL_CHECK(glGenBuffers(1, &VBO));
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    // Allocate buffer with maximum particle data (2 pos + 4 color + 1 size = 7 floats per particle)
    GL_CHECK(glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * sizeof(float) * 7, NULL, GL_DYNAMIC_DRAW));

    // Define vertex attributes
    // Position (2 floats)
    GL_CHECK(glEnableVertexAttribArray(0));
    GL_CHECK(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0));
    // Color (4 floats)
    GL_CHECK(glEnableVertexAttribArray(1));
    GL_CHECK(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float))));
    // Point Size (1 float)
    GL_CHECK(glEnableVertexAttribArray(2));
    GL_CHECK(glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(6 * sizeof(float))));

    // Unbind VAO
    GL_CHECK(glBindVertexArray(0));

    // Load particle texture
    particleTexture = loadTexture("assets/particle.png"); // Ensure 'assets/particle.png' exists in your project directory
    if (particleTexture == 0) {
        printf("Warning: Particle texture not loaded. Texture-based particles will be disabled.\n");
    }

    // Set texture uniform in shader
    GL_CHECK(glUseProgram(shaderProgram));
    particleTextureLocation = glGetUniformLocation(shaderProgram, "particleTexture");
    if (particleTextureLocation == -1) {
        printf("Failed to find 'particleTexture' uniform location.\n");
    }
    GL_CHECK(glUniform1i(particleTextureLocation, 0)); // Texture unit 0

    // Get uniform location for 'useTexture'
    useTextureLocation = glGetUniformLocation(shaderProgram, "useTexture");
    if (useTextureLocation == -1) {
        printf("Failed to find 'useTexture' uniform location.\n");
    }

    GL_CHECK(glUseProgram(0));
}

// Function to update VBO data with current particles
void updateVBO(int maxParticlesToUpdate) {
    // Allocate a buffer to store particle data
    // 2 floats for position, 4 for color, 1 for size = 7 floats per particle
    float* data = new float[maxParticlesToUpdate * 7];
    for (int i = 0; i < maxParticlesToUpdate; i++) {
        data[i * 7 + 0] = particles[i].x;
        data[i * 7 + 1] = particles[i].y;
        data[i * 7 + 2] = particles[i].r;
        data[i * 7 + 3] = particles[i].g;
        data[i * 7 + 4] = particles[i].b;
        data[i * 7 + 5] = particles[i].a;
        data[i * 7 + 6] = particles[i].size;
    }

    // Update VBO data
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GL_CHECK(glBufferSubData(GL_ARRAY_BUFFER, 0, maxParticlesToUpdate * 7 * sizeof(float), data));
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));

    delete[] data;
}

// Modified Rendering Function to bind texture and set 'useTexture' uniform
void renderParticlesModern(int maxParticlesToRender, bool useTextureFlag) {
    // Use shader program
    GL_CHECK(glUseProgram(shaderProgram));

    // Bind the texture to texture unit 0
    GL_CHECK(glActiveTexture(GL_TEXTURE0));
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, particleTexture));

    // Set the 'useTexture' uniform
    GL_CHECK(glUniform1i(useTextureLocation, useTextureFlag ? 1 : 0));

    GL_CHECK(glBindVertexArray(VAO));

    // Update VBO with current particle data
    updateVBO(maxParticlesToRender);

    // Draw particles as points
    GL_CHECK(glDrawArrays(GL_POINTS, 0, maxParticlesToRender));

    // Unbind VAO and shader
    GL_CHECK(glBindVertexArray(0));
    GL_CHECK(glUseProgram(0));
}

// Function to reinitialize a particle during respawn or explosion
void reinitParticle(Particle *p, float x, float y, bool isExplosion = false) {
    p->x = x; // Set new x position
    p->y = y; // Set new y position

    p->speedX = ((float)rand() / RAND_MAX) * (maxSpeedX - minSpeedX) + minSpeedX; // Reinitialize random speed on x-axis
    p->speedY = ((float)rand() / RAND_MAX) * (maxSpeedY - minSpeedY) + maxSpeedY; // Reinitialize random speed on y-axis (upwards)

    // Clamp speeds
    if (fabs(p->speedX) < 0.001f) {
        p->speedX = (rand() % 2 == 0) ? 0.001f : -0.001f;
    }
    if (fabs(p->speedY) < 0.001f) {
        p->speedY = 0.001f; // Ensure particles always have upward speed
    }

    // Adjust color based on baseColor with proper clamping
    p->r = baseColor[0] + ((float)rand() / RAND_MAX) * 0.2f; // Bright red up to baseR + 0.2
    if (p->r > 1.0f) p->r = 1.0f; // Clamp to 1.0

    p->g = baseColor[1] + ((float)rand() / RAND_MAX) * 0.5f; // Bright greenish up to baseG + 0.5
    if (p->g > 1.0f) p->g = 1.0f; // Clamp to 1.0

    p->b = baseColor[2] + ((float)rand() / RAND_MAX) * 0.2f; // Slightly brighter blue up to baseB + 0.2
    if (p->b > 1.0f) p->b = 1.0f; // Clamp to 1.0

    p->a = 1.0f; // Fully opaque

    // Assign size based on particle type
    if (isExplosion) {
        p->size = ((float)rand() / RAND_MAX) * (explosionMaxSize - explosionMinSize) + explosionMinSize;
    } else {
        p->size = ((float)rand() / RAND_MAX) * (maxSize - minSize) + minSize;
    }

    // Assign life span based on particle type
    if (isExplosion) {
        p->life = ((float)rand() / RAND_MAX) * (0.6f - 0.2f) + 0.2f; // Shorter life span for explosions
    } else {
        p->life = ((float)rand() / RAND_MAX) * (maxLife - minLife) + minLife; // Regular life span
    }

    // Set explosion capability
    if (isExplosion) {
        p->canExplode = 0; // Explosion particles cannot explode again
    } else {
        p->canExplode = (rand() % 100) < explosionChance; // explosionChance% of particles can explode
    }

    p->exploding = 0; // Reset exploding flag
}

// Function to initialize a single particle with random properties
void initParticle(Particle *p) {
    float initialX = ((float)rand() / RAND_MAX - 0.5f) * 0.15f; // Initial x position with random spread
    float initialY = -0.75f;                                   // Initial y position (bottom of the screen)
    reinitParticle(p, initialX, initialY, false); // Initialize as regular particle

    // Debug: Print base color
    // printf("Initialized Particle with Base Color: R=%.2f, G=%.2f, B=%.2f\n", baseColor[0], baseColor[1], baseColor[2]);
}

// Function to initialize all particles
void initParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        initParticle(&particles[i]); // Initialize each particle as regular
    }
    printf("All particles initialized.\n");
}

// Function to create an explosion of smaller, brighter particles at the given position
void createExplosion(float x, float y) {
    for (int i = 0; i < EXPLOSION_PARTICLES; i++) {
        int index = rand() % maxParticles;  // Use random index within active particles
        Particle *p = &particles[index];

        // Reinitialize the particle at the explosion position as an explosion particle
        reinitParticle(p, x, y, true);
    }
    printf("Created explosion at (%.2f, %.2f) with %d particles.\n", x, y, EXPLOSION_PARTICLES);

    // Optional: Play explosion sound effect (if implemented)
    // playExplosionSound(); // Implement this function similarly to playClickSound()
}

// Function to update all particles
void updateParticles(float deltaTime, int maxParticlesToUpdate, int explosionChance) {
    for (int i = 0; i < maxParticlesToUpdate; i++) {
        // Update particle position based on speed and elapsed time
        particles[i].x += particles[i].speedX * deltaTime;
        particles[i].y += particles[i].speedY * deltaTime;

        // Introduce randomness in speed to simulate interaction
        particles[i].speedX += ((float)rand() / RAND_MAX - 0.5f) * 0.008f;
        particles[i].speedY += ((float)rand() / RAND_MAX - 0.51f) * 0.018f;

        // Add slight upward acceleration to simulate buoyancy effect
        particles[i].speedY += 0.001f;

        // Apply damping to speed to smooth out movement
        particles[i].speedX *= 0.99f;
        particles[i].speedY *= 0.99f;

        // Clamp speeds again to prevent particles from freezing
        if (fabs(particles[i].speedX) < 0.001f) {
            particles[i].speedX = (rand() % 2 == 0) ? 0.001f : -0.001f;
        }
        if (fabs(particles[i].speedY) < 0.001f) {
            particles[i].speedY = 0.001f; // Ensure particles always have upward speed
        }

        // Decrease particle life over time and update alpha value
        particles[i].life -= deltaTime * 0.1f;
        particles[i].a = particles[i].life; // Alpha is proportional to remaining life

        // Random chance for a particle to explode if it can explode
        if (particles[i].canExplode && !particles[i].exploding && (rand() % 1000) < explosionChance) {  // Explosion chance controlled by user
            particles[i].exploding = 1; // Mark particle as exploding
            createExplosion(particles[i].x, particles[i].y); // Create an explosion at particle's position
            particles[i].life = 0.0f; // End the life of the exploding particle
            printf("Particle %d exploded at (%.2f, %.2f)\n", i, particles[i].x, particles[i].y);

            // Play explosion sound effect (if implemented)
            // playExplosionSound(); // Implement this function similarly to playClickSound()
        }

        // Respawn the particle if its life ends
        if (particles[i].life <= 0.0f) {
            initParticle(&particles[i]); // Reinitialize particle when life ends
        }

        // Debug: Print positions and sizes of first 5 particles
        /*
        if (i < 5) {
            printf("Particle %d Position: (%.2f, %.2f), Size: %.2f, Color: R=%.2f, G=%.2f, B=%.2f, A=%.2f\n",
                   i, particles[i].x, particles[i].y, particles[i].size,
                   particles[i].r, particles[i].g, particles[i].b, particles[i].a);
        }
        */
    }
}

// Function to format time as MM:SS
std::string formatTime(float seconds) {
    int minutes = static_cast<int>(seconds) / 60;
    int secs = static_cast<int>(seconds) % 60;
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, secs);
    return std::string(buffer);
}

// Function to shutdown rendering resources
void shutdownRendering() {
    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    // Delete texture
    glDeleteTextures(1, &particleTexture);
}

// Function to shutdown audio resources
void shutdownAudio() {
    Mix_FreeChunk(clickSound);
    Mix_FreeChunk(clickClockSound);
    Mix_FreeChunk(startSound);
    Mix_FreeChunk(finishCountdownSound);
    Mix_FreeMusic(bgm);
    Mix_CloseAudio();
    SDL_Quit();
}

// Callback function to adjust the OpenGL viewport when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Prevent division by zero
    if (height == 0)
        height = 1;

    // Set the viewport to cover the new window size
    glViewport(0, 0, width, height);
}

// Main function
int main() {
    // Initialize GLFW library
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Specify OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on Mac

    // Explicitly set the window to be resizable
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // Create a window with OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Bonfire Simulator with Pomodoro Timer", NULL, NULL);
    if (!window) {
        glfwTerminate();
        printf("Failed to create GLFW window\n");
        return -1;
    }

    glfwMakeContextCurrent(window); // Make the created window the current context for OpenGL

    // Register the framebuffer size callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize ImGui
    ImGui_Init(window);

    // Initialize GLEW and modern OpenGL rendering
    initRendering();

    // Initialize SDL2 and SDL_mixer for audio
    if (!initAudio()) {
        printf("Audio initialization failed.\n");
        shutdownRendering();
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Load audio assets
    if (!loadAudio()) {
        printf("Loading audio assets failed.\n");
        shutdownAudio();
        shutdownRendering();
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Play background music
    playBackgroundMusic();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set a plain black background

    initParticles(); // Initialize all particles

    // Variables to track size changes
    static float previousMinSize = minSize;
    static float previousMaxSize = maxSize;
    bool sizeChanged = false;

    // Variables to track explosion size changes
    static float previousExplosionMinSize = explosionMinSize;
    static float previousExplosionMaxSize = explosionMaxSize;
    bool explosionSizeChanged = false;

    // Variable to track texture usage
    bool useTexture = false;

    // Initialize timing variables
    double lastTime = glfwGetTime(); // GLFW's time in seconds

    // Main loop: runs until the window is closed
    while (!glfwWindowShouldClose(window)) {
        // Calculate deltaTime
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        // Optional: Clamp deltaTime to prevent issues on frame drops
        if (deltaTime > 0.1f) {
            deltaTime = 0.1f; // Cap to 100ms
        }

        // Clear the screen each frame to avoid ghosting or trails from previous particles
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Start a new ImGui frame
        ImGui_NewFrame();

        // === 1. Particle Controls Window ===
        ImGui::Begin("Particle Controls", nullptr, ImGuiWindowFlags_NoCollapse); // Allow resizing

        ImGui::Text("=== Particle Controls ===");
        // Sliders to control particle simulation parameters
        ImGui_AddSliderInt("Max Particles", &maxParticles, 100, MAX_PARTICLES);
        ImGui_AddSliderInt("Explosion Chance (%%):", &explosionChance, 1, 100); // Fixed '%' to '%%'

        // Particle Size Controls
        ImGui_AddSliderFloat("Min Size", &minSize, 1.0f, 50.0f);
        ImGui_AddSliderFloat("Max Size", &maxSize, minSize, 100.0f);

        // Explosion Particle Size Controls
        ImGui_AddSliderFloat("Explosion Min Size", &explosionMinSize, 0.5f, 5.0f);
        ImGui_AddSliderFloat("Explosion Max Size", &explosionMaxSize, explosionMinSize, 10.0f);

        // Particle Life Controls
        ImGui_AddSliderFloat("Min Life", &minLife, 0.01f, 2.0f);
        ImGui_AddSliderFloat("Max Life", &maxLife, minLife, 5.0f);

        // Particle Speed Controls
        ImGui_AddSliderFloat("Min Speed X", &minSpeedX, -0.1f, 0.0f);
        ImGui_AddSliderFloat("Max Speed X", &maxSpeedX, 0.0f, 0.1f);
        ImGui_AddSliderFloat("Min Speed Y", &minSpeedY, 0.0f, 0.1f);
        ImGui_AddSliderFloat("Max Speed Y", &maxSpeedY, minSpeedY, 0.2f);

        // Color Controls (Use color picker)
        ImGui_AddColorEdit3("Base Color", baseColor);

        // === Audio Controls ===
        ImGui::Separator();
        ImGui::Text("=== Audio Controls ===");
        // Volume Control Slider
        ImGui::SliderFloat("Music Volume", &musicVolume, 0.0f, 1.0f);
        // Display the volume percentage next to the slider
        ImGui::SameLine();
        ImGui::Text("%.0f%%", musicVolume * 100.0f);
        // Update the music volume based on slider
        Mix_VolumeMusic(static_cast<int>(musicVolume * MIX_MAX_VOLUME));

        // Button to toggle texture usage
        if (ImGui::Button(useTexture ? "Deactivate Texture" : "Activate Texture")) { // Toggle button label
            if (particleTexture != 0) { // Only allow activation if texture is loaded
                useTexture = !useTexture;
                printf("Texture usage %s.\n", useTexture ? "activated" : "deactivated");
                playClickClockSound(); // Play Pomodoro button click sound when toggling texture
            } else {
                printf("Cannot activate texture. Texture not loaded.\n");
                // Notify the user via ImGui
                ImGui::OpenPopup("Texture Error");
            }
        }

        // Optional: Popup for texture error
        if (ImGui::BeginPopup("Texture Error")) {
            ImGui::Text("Particle texture not loaded.");
            if (ImGui::Button("OK")) {
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }

        // === Additional Actions ===
        ImGui::Separator();
        ImGui::Text("=== Additional Actions ===");
        if (ImGui::Button("Reset Particles")) {
            initParticles();
            printf("Particles reset.\n");
            playClickSound(); // Play click sound when button is pressed
        }
        ImGui::SameLine();
        if (ImGui::Button("Trigger Explosion")) {
            // Create an explosion at a random position within a certain range
            float explosionX = ((float)rand() / RAND_MAX - 0.5f) * 0.15f;
            float explosionY = -0.75f + ((float)rand() / RAND_MAX) * 1.5f; // Between bottom and top
            createExplosion(explosionX, explosionY);
            printf("Explosion triggered at (%.2f, %.2f)\n", explosionX, explosionY);
            playClickSound(); // Play click sound when button is pressed
        }

        // Display current parameter values
        ImGui::Separator();
        ImGui::Text("=== Current Parameters ===");
        ImGui::Text("Particle Count: %d", maxParticles);
        ImGui::Text("Explosion Chance: %d%%", explosionChance);

        ImGui::End(); // End of Particle Controls Window

        // === 2. Pomodoro Timer Window ===
        ImGui::Begin("Pomodoro Timer", nullptr, ImGuiWindowFlags_NoCollapse); // Allow resizing

        ImGui::Text("=== Pomodoro Timer ===");

        // Pomodoro Duration Selection
        const char* durations[] = { "15 Minutes", "25 Minutes", "50 Minutes" };
        static int currentDuration = 1; // Default to "25 Minutes"

        if (ImGui::Combo("Select Duration", &currentDuration, durations, IM_ARRAYSIZE(durations))) {
            // Play button click sound when changing duration
            playClickClockSound();
            // Set timer duration based on selection
            if (currentDuration == 0)
                timerDuration = 900.0f; // 15 minutes
            else if (currentDuration == 1)
                timerDuration = 1500.0f; // 25 minutes
            else if (currentDuration == 2)
                timerDuration = 3000.0f; // 50 minutes

            // Reset remaining time
            timerRemaining = timerDuration;
            timerState = STOPPED;
        }

        // Determine color based on timer state
        ImVec4 timerColor;
        if (timerState == RUNNING) {
            timerColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Green
        }
        else if (timerState == PAUSED) {
            timerColor = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow
        }
        else if (timerFinished) {
            timerColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red
        }
        else {
            timerColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // White
        }

        // Start Font Scaling using PushFont
        if (g_largeFont) {
            ImGui::PushFont(g_largeFont);
        }

        // Apply color to the timer text
        ImGui::PushStyleColor(ImGuiCol_Text, timerColor);

        // Display the countdown timer
        std::string timerDisplay = formatTime(timerRemaining);
        ImGui::Text("Time Remaining: %s", timerDisplay.c_str());

        ImGui::PopStyleColor(); // Restore original text color
        if (g_largeFont) {
            ImGui::PopFont();
        }
        // End Font Scaling

        // Add spacing between timer and progress bar
        ImGui::Spacing();

        // Render progress bar with timer text as label
        float progress = (timerDuration - timerRemaining) / timerDuration;
        ImGui::ProgressBar(progress, ImVec2(0.0f, 0.0f), timerDisplay.c_str());

        // Pomodoro Control Buttons
        // Start Button
        if (ImGui::Button("Start")) {
            if (timerState != RUNNING) {
                timerState = RUNNING;
                playStartSound(); // Play start timer sound
            }
            playClickClockSound(); // Play button click sound
        }
        ImGui::SameLine();
        // Pause Button
        if (ImGui::Button("Pause")) {
            if (timerState == RUNNING) {
                timerState = PAUSED;
            }
            playClickClockSound(); // Play button click sound
        }
        ImGui::SameLine();
        // Reset Button
        if (ImGui::Button("Reset")) {
            timerState = STOPPED;
            timerRemaining = timerDuration;
            playClickClockSound(); // Play button click sound
        }

        ImGui::End(); // End of Pomodoro Timer Window

        // Handle Timer Completion Popup
        if (timerFinished) {
            ImGui::OpenPopup("Timer Finished");

            if (ImGui::BeginPopup("Timer Finished")) {
                ImGui::Text("Pomodoro Timer Completed!");
                if (ImGui::Button("OK")) {
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }
        }

        // Check for regular size changes
        if (minSize != previousMinSize || maxSize != previousMaxSize) {
            sizeChanged = true;
            previousMinSize = minSize;
            previousMaxSize = maxSize;
            printf("Size changed: Min Size = %.2f, Max Size = %.2f\n", minSize, maxSize);
        }

        // If regular size has changed, update all regular particle sizes
        if (sizeChanged) {
            for (int i = 0; i < maxParticles; i++) { // Loop up to maxParticles
                // Only update size if the particle is not exploding
                if (!particles[i].exploding) {
                    particles[i].size = ((float)rand() / RAND_MAX) * (maxSize - minSize) + minSize;
                    // Debug: Print new size for the first few particles
                    /*
                    if (i < 5) {
                        printf("Particle %d New Size: %.2f\n", i, particles[i].size);
                    }
                    */
                }
            }
            sizeChanged = false;
            printf("All regular particle sizes updated based on new minSize and maxSize.\n");
        }

        // Check for explosion size changes
        if (explosionMinSize != previousExplosionMinSize || explosionMaxSize != previousExplosionMaxSize) {
            explosionSizeChanged = true;
            previousExplosionMinSize = explosionMinSize;
            previousExplosionMaxSize = explosionMaxSize;
            printf("Explosion Size changed: Min Size = %.2f, Max Size = %.2f\n", explosionMinSize, explosionMaxSize);
        }

        // If explosion size has changed, update all explosion particle sizes
        if (explosionSizeChanged) {
            for (int i = 0; i < maxParticles; i++) { // Loop up to maxParticles
                // Only update size if the particle is exploding
                if (particles[i].exploding) {
                    particles[i].size = ((float)rand() / RAND_MAX) * (explosionMaxSize - explosionMinSize) + explosionMinSize;
                    // Debug: Print new size for the first few explosion particles
                    /*
                    if (i < 5) {
                        printf("Particle %d New Explosion Size: %.2f\n", i, particles[i].size);
                    }
                    */
                }
            }
            explosionSizeChanged = false;
            printf("All explosion particle sizes updated based on new explosionMinSize and explosionMaxSize.\n");
        }

        // Handle Pomodoro Timer Logic
        if (timerState == RUNNING) {
            timerRemaining -= deltaTime;
            if (timerRemaining <= 0.0f && !timerFinished) {
                timerRemaining = 0.0f;
                timerState = STOPPED;
                timerFinished = true;
                playFinishCountdownSound(); // Play finish countdown sound
                printf("Pomodoro Timer Finished!\n");
            }
        }

        // Reset timerFinished flag if timer is restarted
        if (timerState == RUNNING && timerFinished) {
            timerFinished = false;
        }

        // Update particle system with current user-controlled values
        updateParticles(deltaTime, maxParticles, explosionChance);

        // Render all particles using modern OpenGL with texture usage flag
        renderParticlesModern(maxParticles, useTexture);

        // Render ImGui
        ImGui_Render();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Shutdown rendering resources
    shutdownRendering();

    // Shutdown audio resources
    shutdownAudio();

    // Shutdown ImGui
    ImGui_Shutdown();
    glfwDestroyWindow(window); // Destroy the window
    glfwTerminate(); // Terminate the GLFW library
    return 0; // Exit the program
}

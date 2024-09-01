#include <stdio.h>    // Standard Input/Output library for printf and file handling
#include <GLFW/glfw3.h> // GLFW library for handling window and OpenGL context
#include <stdlib.h>   // Standard library for general functions like malloc, rand, etc.
#include <math.h>     // Math library for mathematical functions

#define MAX_PARTICLES 3000   // Maximum number of particles in the simulation
#define EXPLOSION_PARTICLES 30   // Number of particles created in an explosion
#define EXPLOSION_CHANCE 1   // Percentage of particles that can explode

// Structure to represent a particle in the simulation
typedef struct {
    float x, y;        // Position of the particle
    float speedX, speedY;  // Speed of the particle
    float r, g, b, a;  // Color (RGB) and alpha (opacity)
    float size;        // Size of the particle
    float life;        // Remaining life of the particle
    int canExplode;    // Flag to indicate if this particle has the ability to explode
    int exploding;     // Flag to indicate if this particle is exploding
} Particle;

Particle particles[MAX_PARTICLES]; // Array to store all particles

// Function to initialize a single particle with random properties
void initParticle(Particle *p) {
    p->x = ((float)rand() / RAND_MAX - 0.5f) * 0.15f; // Initial position on x-axis with random spread
    p->y = -0.75f; // Initial position on y-axis

    p->speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.02f; // Random initial speed on x-axis
    p->speedY = ((float)rand() / RAND_MAX) * 0.05f + 0.1f; // Random initial speed on y-axis

    p->r = 1.0f; // Red color
    p->g = (float)rand() / RAND_MAX * 0.5f; // Random green value for color variation
    p->b = 0.0f; // Blue is 0 (yellowish color)
    p->a = 1.0f; // Alpha (fully opaque)

    p->size = ((float)rand() / RAND_MAX) * 4.0f + 1.0f; // Random size
    p->life = ((float)rand() / RAND_MAX) * 1.2f + 0.05f; // Random life span

    // Only a small percentage of particles are set to explode
    p->canExplode = (rand() % 100) < EXPLOSION_CHANCE; // EXPLOSION_CHANCE percentage of particles can explode
    p->exploding = 0; // Not exploding initially
}

// Function to initialize all particles
void initParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        initParticle(&particles[i]); // Initialize each particle
    }
}

// Function to create an explosion of smaller, brighter particles at the given position
void createExplosion(float x, float y) {
    for (int i = 0; i < EXPLOSION_PARTICLES; i++) {
        int index = rand() % MAX_PARTICLES;  // Use random index to replace existing particle
        Particle *p = &particles[index];

        p->x = x; // Position of the explosion
        p->y = y;
        
        // Speed with a more erratic random spread
        p->speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
        p->speedY = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;

        // Set brighter color for sparks: same tone, increased brightness
        p->r = fmin(1.2f, 1.0f + ((float)rand() / RAND_MAX * 0.2f)); // Bright red
        p->g = fmin(1.0f, (float)rand() / RAND_MAX * 0.6f + 0.4f); // Bright greenish
        p->b = fmin(0.2f, (float)rand() / RAND_MAX * 0.2f); // Slightly brighter yellowish

        p->a = 1.0f; // Alpha (fully opaque)
        p->size = ((float)rand() / RAND_MAX) * 2.0f + 1.0f; // Smaller size for explosion particles
        p->life = ((float)rand() / RAND_MAX) * 0.6f + 0.2f; // Shorter life span
        p->canExplode = 0; // New particles do not explode
        p->exploding = 0; // New particles do not explode
    }
}

// Function to update all particles
void updateParticles(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
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

        // Decrease particle life over time and update alpha value
        particles[i].life -= deltaTime * 0.1f;
        particles[i].a = particles[i].life; // Alpha is proportional to remaining life

        // Random chance for a particle to explode if it can explode
        if (particles[i].canExplode && !particles[i].exploding && (rand() % 1000) < 1) {  // 0.1% chance per frame
            particles[i].exploding = 1; // Mark particle as exploding
            createExplosion(particles[i].x, particles[i].y); // Create an explosion at particle's position
            particles[i].life = 0.0f; // End the life of the exploding particle
        }

        // Respawn the particle if its life ends
        if (particles[i].life <= 0.0f) {
            initParticle(&particles[i]);
        }
    }
}

// Function to render all particles
void renderParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        glPointSize(particles[i].size); // Set the size of the particle
        glColor4f(particles[i].r, particles[i].g, particles[i].b, particles[i].a); // Set the color and alpha
        glBegin(GL_POINTS); // Start rendering points
        glVertex2f(particles[i].x, particles[i].y); // Specify particle position
        glEnd();
    }
}

// Main function
int main() {
    // Initialize GLFW library
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Create a window with OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Your Bonfire", NULL, NULL);
    if (!window) { // If window creation fails, clean up and exit
        glfwTerminate();
        printf("Failed to create GLFW window\n");
        return -1;
    }

    glfwMakeContextCurrent(window); // Make the created window the current context for OpenGL

    glPointSize(2.0f); // Set initial point size for rendering particles
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set a plain black background

    initParticles(); // Initialize all particles

    // Main loop: runs until the window is closed
    while (!glfwWindowShouldClose(window)) {
        float deltaTime = 0.016f; // Fixed time step for consistent particle updates

        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

        updateParticles(deltaTime); // Update particle positions and properties
        renderParticles(); // Render all particles

        glfwSwapBuffers(window); // Swap front and back buffers to display rendered image
        glfwPollEvents(); // Poll for and process events (e.g., keyboard, mouse)
    }

    glfwDestroyWindow(window); // Destroy the created window
    glfwTerminate(); // Terminate the GLFW library
    return 0; // Exit the program
}

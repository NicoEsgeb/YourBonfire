#include <stdio.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PARTICLES 1000

typedef struct {
    unsigned char* data;
    int width;
    int height;
} Texture;

Texture loadPPM(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open texture file %s\n", filename);
        exit(1);
    }

    char buffer[16];
    fgets(buffer, sizeof(buffer), fp);

    int width, height, maxval;
    fscanf(fp, "%d %d", &width, &height);
    fscanf(fp, "%d", &maxval);
    fgetc(fp);

    unsigned char* data = (unsigned char*)malloc(3 * width * height);
    fread(data, 3, width * height, fp);

    fclose(fp);

    Texture texture = { data, width, height };
    return texture;
}

void renderTexture(Texture texture, float x, float y, float width, float height) {
    glEnable(GL_TEXTURE_2D);
    
    // Bind the texture
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture.data);

    // Render the quad with the texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + height);
    glEnd();

    glDeleteTextures(1, &tex);
    glDisable(GL_TEXTURE_2D);
}

typedef struct {
    float x, y;        // Position of the particle
    float speedX, speedY;  // Speed of the particle
    float r, g, b, a;  // Color and alpha (opacity)
    float size;        // Size of the particle
    float life;        // Remaining life of the particle
} Particle;

Particle particles[MAX_PARTICLES];

void initParticle(Particle *p) {
    // Expanded source area for the embers
    p->x = ((float)rand() / RAND_MAX - 0.5f) * 0.2f; // Spread source on x-axis
    p->y = -0.75f;

    // Initial speeds with slight variations
    p->speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.02f;
    p->speedY = ((float)rand() / RAND_MAX) * 0.05f + 0.1f;

    p->r = 1.0f;
    p->g = (float)rand() / RAND_MAX * 0.5f;
    p->b = 0.0f;
    p->a = 1.0f;

    p->size = ((float)rand() / RAND_MAX) * 2.0f + 1.0f;
    p->life = ((float)rand() / RAND_MAX) * 0.5f + 0.5f;
}

void initParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        initParticle(&particles[i]);
    }
}

void updateParticles(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        // Update position
        particles[i].x += particles[i].speedX * deltaTime;
        particles[i].y += particles[i].speedY * deltaTime;

        // Introduce interaction-like randomness
        particles[i].speedX += ((float)rand() / RAND_MAX - 0.5f) * 0.004f;
        particles[i].speedY += ((float)rand() / RAND_MAX - 0.5f) * 0.004f;

        // Add slight upward acceleration to simulate buoyancy
        particles[i].speedY += 0.001f;

        // Apply slight damping to both speedX and speedY for smoother movement
        particles[i].speedX *= 0.99f;
        particles[i].speedY *= 0.99f;

        // Decrease life and update alpha value
        particles[i].life -= deltaTime * 0.1f;
        particles[i].a = particles[i].life;

        // Respawn particle immediately if its life ends
        if (particles[i].life <= 0.0f) {
            initParticle(&particles[i]);
        }
    }
}

void renderParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        glPointSize(particles[i].size);
        glColor4f(particles[i].r, particles[i].g, particles[i].b, particles[i].a);
        glBegin(GL_POINTS);
        glVertex2f(particles[i].x, particles[i].y);
        glEnd();
    }
}

int main() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Your Bonfire", NULL, NULL);
    if (!window) {
        glfwTerminate();
        printf("Failed to create GLFW window\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    glPointSize(2.0f);

    Texture logTexture = loadPPM("log_texture.ppm"); // Replace with your actual texture file
    initParticles();

    while (!glfwWindowShouldClose(window)) {
        float deltaTime = 0.016f;

        glClear(GL_COLOR_BUFFER_BIT);

        renderTexture(logTexture, -0.5f, -0.75f, 1.0f, 0.5f); // Adjust size and position as needed
        updateParticles(deltaTime);
        renderParticles();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    free(logTexture.data);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

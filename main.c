#include <stdio.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PARTICLES 1000

typedef struct {
    float x, y;        // Position of the particle
    float speedX, speedY;  // Speed of the particle
    float r, g, b, a;  // Color and alpha (opacity)
    float life;        // Remaining life of the particle
} Particle;

Particle particles[MAX_PARTICLES];

void initParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].x = 0.0f;
        particles[i].y = -0.5f; // Start near the bottom
        particles[i].speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
        particles[i].speedY = ((float)rand() / RAND_MAX) * 0.05f;
        particles[i].r = 1.0f; // Red color for fire
        particles[i].g = (float)rand() / RAND_MAX * 0.5f; // Varying yellow
        particles[i].b = 0.0f; // No blue component
        particles[i].a = 1.0f;
        particles[i].life = 1.0f; // Start with full life
    }
}

void updateParticles(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].x += particles[i].speedX;
        particles[i].y += particles[i].speedY;
        particles[i].life -= deltaTime * 0.5f; // Decrease life over time
        particles[i].a = particles[i].life; // Fade out
        if (particles[i].life <= 0.0f) {
            // Respawn particle
            particles[i].x = 0.0f;
            particles[i].y = -0.5f;
            particles[i].speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
            particles[i].speedY = ((float)rand() / RAND_MAX) * 0.05f;
            particles[i].life = 1.0f;
        }
    }
}

void renderParticles() {
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_PARTICLES; i++) {
        glColor4f(particles[i].r, particles[i].g, particles[i].b, particles[i].a);
        glVertex2f(particles[i].x, particles[i].y);
    }
    glEnd();
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

    glPointSize(2.0f); // Set point size for particles

    initParticles();

    while (!glfwWindowShouldClose(window)) {
        float deltaTime = 0.016f; // Assuming 60 FPS

        glClear(GL_COLOR_BUFFER_BIT);

        updateParticles(deltaTime);
        renderParticles();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

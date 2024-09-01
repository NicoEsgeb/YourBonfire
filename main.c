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
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture.data);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(x + width, y);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(x + width, y + height);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + height);
    glEnd();

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

void initParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].x = 0.0f;
        particles[i].y = -0.5f;
        particles[i].speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
        particles[i].speedY = ((float)rand() / RAND_MAX) * 0.05f;
        particles[i].r = 1.0f;
        particles[i].g = (float)rand() / RAND_MAX * 0.5f;
        particles[i].b = 0.0f;
        particles[i].a = 1.0f;
        particles[i].size = ((float)rand() / RAND_MAX) * 5.0f + 1.0f; // Random size between 1 and 6
        particles[i].life = 1.0f;
    }
}


void updateParticles(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].x += particles[i].speedX * deltaTime;
        particles[i].y += particles[i].speedY * deltaTime;
        particles[i].speedX += (float)(rand() % 10 - 5) * 0.001f; // Add a slight random curve to the motion
        particles[i].life -= deltaTime * 0.5f;
        particles[i].a = particles[i].life;
        if (particles[i].life <= 0.0f) {
            particles[i].x = 0.0f;
            particles[i].y = -0.5f;
            particles[i].speedX = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
            particles[i].speedY = ((float)rand() / RAND_MAX) * 0.05f;
            particles[i].size = ((float)rand() / RAND_MAX) * 5.0f + 1.0f;
            particles[i].life = 1.0f;
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

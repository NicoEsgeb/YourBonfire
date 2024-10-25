// minimal_main.cpp
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "imgui_wrapper.h"

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Specify OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on Mac

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "ImGui Test", NULL, NULL);
    if (!window) {
        glfwTerminate();
        printf("Failed to create GLFW window\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize ImGui
    ImGui_Init(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Start ImGui frame
        ImGui_NewFrame();

        // Create a window and add a button
        ImGui::Begin("Test Window");
        if (ImGui_Button("Click Me")) {
            printf("Button Clicked!\n");
        }
        ImGui::End();

        // Render ImGui
        ImGui_Render();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Shutdown ImGui
    ImGui_Shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

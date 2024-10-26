// imgui_wrapper.cpp
#include <stdio.h>              // Include for printf
#include "imgui_wrapper.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// Define the global font pointer
ImFont* g_largeFont = nullptr;

// Initialize ImGui
void ImGui_Init(GLFWwindow* window) {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Load default font
    io.Fonts->AddFontDefault();

    // Load custom large font
    g_largeFont = io.Fonts->AddFontFromFileTTF("assets/Arial.ttf", 24.0f); // Adjusted to 24.0f
    if (!g_largeFont) {
        printf("Failed to load large font! Using default font.\n");
        // Optionally, set a fallback font or notify the user via the UI
    }

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150"); // Updated GLSL version for macOS
}

// Start a new ImGui frame
void ImGui_NewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

// Add an integer slider
void ImGui_AddSliderInt(const char* label, int* value, int min, int max) {
    ImGui::SliderInt(label, value, min, max);
}

// Add a float slider
void ImGui_AddSliderFloat(const char* label, float* value, float min, float max) {
    ImGui::SliderFloat(label, value, min, max);
}

// Add a color editor (3 floats)
void ImGui_AddColorEdit3(const char* label, float* color) {
    ImGui::ColorEdit3(label, color);
}

// Add a button
int ImGui_Button(const char* label) {
    return ImGui::Button(label);
}

// Render ImGui
void ImGui_Render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// Shutdown ImGui
void ImGui_Shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

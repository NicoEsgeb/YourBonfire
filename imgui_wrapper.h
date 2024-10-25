// imgui_wrapper.h
#ifndef IMGUI_WRAPPER_H
#define IMGUI_WRAPPER_H

#include <GLFW/glfw3.h>
#include "imgui.h" // Include ImGui core header

// Initialize ImGui
void ImGui_Init(GLFWwindow* window);

// Start a new ImGui frame
void ImGui_NewFrame();

// Add an integer slider
void ImGui_AddSliderInt(const char* label, int* value, int min, int max);

// Add a float slider
void ImGui_AddSliderFloat(const char* label, float* value, float min, float max);

// Add a color editor (3 floats)
void ImGui_AddColorEdit3(const char* label, float* color);

// Add a button
int ImGui_Button(const char* label);

// Render ImGui
void ImGui_Render();

// Shutdown ImGui
void ImGui_Shutdown();

#endif // IMGUI_WRAPPER_H

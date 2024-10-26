// imgui_wrapper.h
#ifndef IMGUI_WRAPPER_H
#define IMGUI_WRAPPER_H

#include "imgui.h"
#include <GLFW/glfw3.h>

// Declare the global font pointer
extern ImFont* g_largeFont;

// Function declarations
void ImGui_Init(GLFWwindow* window);
void ImGui_NewFrame();
void ImGui_AddSliderInt(const char* label, int* value, int min, int max);
void ImGui_AddSliderFloat(const char* label, float* value, float min, float max);
void ImGui_AddColorEdit3(const char* label, float* color);
int ImGui_Button(const char* label);
void ImGui_Render();
void ImGui_Shutdown();

#endif // IMGUI_WRAPPER_H

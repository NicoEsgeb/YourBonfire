# Makefile

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 \
           -I./imgui \
           -I./imgui/backends \
           -I./imgui_wrapper \
           -I/opt/homebrew/include \
           -I/opt/homebrew/opt/glfw/include \
           -I/opt/homebrew/opt/glew/include \
           -DGL_SILENCE_DEPRECATION \
           -O2 \
           -Wall

# Linker Flags
LDFLAGS = -L/opt/homebrew/lib \
          -lglfw \
          -lGLEW \
          -framework OpenGL \
          -lm \
          -ldl \
          -lSDL2 \
          -lSDL2_mixer

# Source Files
SOURCES = main.cpp \
          imgui_wrapper.cpp \
          imgui/imgui.cpp \
          imgui/imgui_draw.cpp \
          imgui/imgui_widgets.cpp \
          imgui/imgui_tables.cpp \
          imgui/imgui_impl_glfw.cpp \
          imgui/imgui_impl_opengl3.cpp

# Object Files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable Name
EXECUTABLE = your_bonfire

# Default Target
all: $(EXECUTABLE)

# Link Object Files to Create Executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile .cpp Files to .o Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build Artifacts
clean:
	rm -f $(EXECUTABLE) *.o imgui/*.o imgui/backends/*.o imgui_wrapper/*.o

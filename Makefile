# Makefile

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 \
           -I./imgui \
           -I/opt/homebrew/include \
           -I/opt/homebrew/opt/glfw/include \
           -I/opt/homebrew/opt/glew/include \
           -DGL_SILENCE_DEPRECATION

# Linker Flags
LDFLAGS = -L/opt/homebrew/lib \
          -L/opt/homebrew/opt/glfw/lib \
          -L/opt/homebrew/opt/glew/lib \
          -lglfw -lGLEW -lSDL2 -lSDL2_mixer \
          -framework OpenGL

# Source Files
SRCS = main.cpp imgui_wrapper.cpp \
       imgui/imgui.cpp imgui/imgui_draw.cpp \
       imgui/imgui_widgets.cpp imgui/imgui_tables.cpp \
       imgui/imgui_impl_glfw.cpp imgui/imgui_impl_opengl3.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Target Executable
TARGET = your_bonfire

# Default Rule
all: $(TARGET)

# Build Rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Rule
clean:
	rm -f $(TARGET) *.o imgui/*.o

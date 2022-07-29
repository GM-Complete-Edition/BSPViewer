cmake_minimum_required(VERSION 3.22)

project(BSPViewer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("thirdparty")

add_executable(
	BSPViewer 
	src/main.cpp src/IO.cpp src/Graphics/PerspectiveCamera.cpp src/Graphics/Buffers/Buffer.cpp
	src/Graphics/Buffers/DepthStencilBuffer.cpp src/Graphics/Buffers/FrameBuffer.cpp src/Graphics/Buffers/IndexBuffer.cpp
	src/Graphics/Buffers/RenderBuffer.cpp src/Graphics/Buffers/VertexBuffer.cpp src/Graphics/Shaders/Shader.cpp
	src/Graphics/Shaders/ShaderStage.cpp src/Graphics/Textures/Texture.cpp src/Graphics/Textures/Texture2D.cpp
)
target_include_directories(BSPViewer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(BSPViewer PUBLIC glad glfw glm ImGUI libbsp nativefiledialog)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_options(BSPViewer PRIVATE /W4)
else()
	target_compile_options(BSPViewer PRIVATE -Wall -Wextra -Wpedantic)
endif()

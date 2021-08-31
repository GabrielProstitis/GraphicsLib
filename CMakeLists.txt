cmake_minimum_required(VERSION 3.0)
project(GraphicsLib)

set (CMAKE_CXX_STANDARD 17)

find_package (OpenGL REQUIRED COMPONENTS OpenGL)

add_subdirectory(dependencies/glfw)

file(GLOB SOURCES "src/*.cpp")



add_executable(${PROJECT_NAME} ${SOURCES} "dependencies/Vortex OpenGL Loader/OpenGL.cpp")

target_link_libraries(${PROJECT_NAME} PUBLIC glfw OpenGL::GL) 
target_include_directories(${PROJECT_NAME} PUBLIC "dependencies/Vortex OpenGL Loader" "dependencies/glm" "dependencies/stb_image" "src/Graphics"  OpenGL::GL)
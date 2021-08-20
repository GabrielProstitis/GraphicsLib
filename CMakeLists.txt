cmake_minimum_required(VERSION 3.0)
project(GraphicsLib)

find_package (OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLEW REQUIRED) 

add_subdirectory(dependencies/glfw)

file(GLOB SOURCES "src/*.cpp")



add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC glfw OpenGL::GL GLEW::GLEW) 
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glew/include)
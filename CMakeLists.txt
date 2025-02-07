cmake_minimum_required(VERSION 3.10)

project(AWEngine VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/engine)

# Add executable
add_executable(AWEngine main.cpp render/window.cpp render/shader.cpp render/object.cpp devtools/devtools.cpp)

target_include_directories(AWEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/GLAD/include
    ${CMAKE_SOURCE_DIR}/thirdparty/GLFW3/include
    ${CMAKE_SOURCE_DIR}/thirdparty/GLM/include
)

# GLFW
add_subdirectory(thirdparty/GLFW3)
target_link_libraries(AWEngine PRIVATE glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(AWEngine PRIVATE OpenGL::GL)

# GLAD
add_subdirectory(thirdparty/GLAD)
target_link_libraries(AWEngine PRIVATE glad)

# GLM
add_subdirectory(thirdparty/GLM)
target_link_libraries(AWEngine PRIVATE glm)

# Set output directory
set_target_properties(AWEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

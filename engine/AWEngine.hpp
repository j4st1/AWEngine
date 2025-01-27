#pragma once

#include "AWEngineWindow.hpp"
#include "AWEngineObject.hpp"
#include "button_handler.hpp"
#include "engine_config.hpp"

#define GLFW_INIT_LIB if (!glfwInit()) { printf("Failed to initialize GLFW\n"); exit(-1);}
#define GLAD_INIT_LIB if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { printf("Failed to initialize GLAD\n"); exit(-1); }

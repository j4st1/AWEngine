#include "button_handler.hpp"

void AWEnginePowerOFF(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && !glfwWindowShouldClose(window)){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

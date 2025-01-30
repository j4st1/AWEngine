#include "AWEngineWindow.hpp"

void AWEngineWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

double AWEngineWindow::cursor_x_pos = 0.0;
double AWEngineWindow::cursor_y_pos = 0.0;
void AWEngineWindow::mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos){
    cursor_x_pos = x_pos;
    cursor_y_pos = y_pos;
}

void AWEngineWindow::create_window() {

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (glfwPlatformSupported(GLFW_PLATFORM_WAYLAND)) { glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);}
    else { std::cout << "No Wayland Support" << "\n"; }

    primary_monitor = glfwGetPrimaryMonitor();
    mode = glfwGetVideoMode(primary_monitor);
    window = glfwCreateWindow(WIDTH_SCREEN, HEIGHT_SCREEN, "AWEngine", NULL, NULL);

    if (!window) { std::cout << "Failed to create GLFW window\n"; glfwTerminate(); exit(-1); }

    int WINDOW_POS_X = (mode -> width - WIDTH_SCREEN) / 2;
    int WINDOW_POS_Y = (mode -> height - HEIGHT_SCREEN) / 2;

    glfwSetWindowPos(window, WINDOW_POS_X, WINDOW_POS_Y);

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetCursorPosCallback(window, mouse_position_callback);
}

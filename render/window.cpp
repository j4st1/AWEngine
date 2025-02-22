// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Window for creating window, get cursor position and etc.             //
//                                                                                      //        
// ************************************************************************************ //


#include "window.hpp"

// callback funcs

void Window::framebuffer_callback ( GLFWwindow* window, int win_width, int win_height ) { glViewport(0, 0, win_width, win_height); }

void Window::mouse_position_callback ( GLFWwindow* windiw, double xpos, double ypos ) { 
   
    cursor_xpos = xpos; cursor_ypos = ypos;
    camera_cursor_xpos = cursor_xpos - last_cursor_xpos;
    camera_cursor_ypos = cursor_ypos - last_cursor_ypos;
    
}
// funcs

void Window::create_window ( void ) {

    glfwWindowHint ( GLFW_SAMPLES, 4 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 6 );
    glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    glfwWindowHint ( GLFW_RED_BITS, mode -> redBits );
    glfwWindowHint ( GLFW_GREEN_BITS, mode -> greenBits );
    glfwWindowHint ( GLFW_BLUE_BITS, mode -> blueBits );

    if ( glfwPlatformSupported( GLFW_PLATFORM_WAYLAND ) ) { glfwInitHint ( GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND ); }
    else { std::cout << "No Wayland Support" << "\n"; }

    glfwWindowHint ( GLFW_REFRESH_RATE, mode -> refreshRate);

    window = glfwCreateWindow ( mode -> width, mode -> height, "AWengine", primary_monitor, nullptr );

    if ( !window ) { std::cout << "Failed to create GLFW window\n"; glfwTerminate ( ); exit ( -1 ); }

    glfwMakeContextCurrent(window);

}

void Window::create_window ( int window_width, int window_height ) {

    glfwWindowHint ( GLFW_SAMPLES, 4 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 6 );
    glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    glfwWindowHint ( GLFW_RED_BITS, mode -> redBits );
    glfwWindowHint ( GLFW_GREEN_BITS, mode -> greenBits );
    glfwWindowHint ( GLFW_BLUE_BITS, mode -> blueBits );

    if ( glfwPlatformSupported( GLFW_PLATFORM_WAYLAND ) ) { glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND); }
    else { std::cout << "No Wayland Support" << "\n"; }

    glfwWindowHint ( GLFW_REFRESH_RATE, mode -> refreshRate);

    window = glfwCreateWindow(window_width, window_height, "AWengine", primary_monitor, nullptr);

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_callback);

    glfwSetCursorPosCallback(window, mouse_position_callback);

}
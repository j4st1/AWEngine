// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Window for creating window, get cursor position and etc.             //
//                                                                                      //        
// ************************************************************************************ //


#include "window.hpp"

// Callback functions

void Window::framebuffer_callback ( GLFWwindow* window, int WIN_WIDTH, int WIN_HEIGHT ) { glViewport ( 0, 0, WIN_WIDTH, WIN_HEIGHT ); }

void Window::mouse_position_callback ( GLFWwindow* window, double xpos, double ypos ) { cursorPos.x = xpos; cursorPos.y = ypos; }

// Functions

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

    glfwMakeContextCurrent ( window );
    glfwSetInputMode ( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback ( window, framebuffer_callback );
    glfwSetCursorPosCallback ( window, mouse_position_callback );

}

void Window::create_window ( int WIN_WIDTH, int WIN_HEIGHT ) {

    this -> WIN_WIDTH = WIN_WIDTH;
    this -> WIN_HEIGHT = WIN_HEIGHT;
    
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

    window = glfwCreateWindow ( WIN_WIDTH, WIN_HEIGHT, "AWEngine", primary_monitor, nullptr );

    glfwMakeContextCurrent ( window );
    glfwSetInputMode ( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback ( window, framebuffer_callback );
    glfwSetCursorPosCallback ( window, mouse_position_callback );

}

void Window::setWindowResolution ( int WIN_WIDTH, int WIN_HEIGHT) { 
    
    this -> WIN_WIDTH = WIN_WIDTH;
    this -> WIN_HEIGHT = WIN_HEIGHT;

    glfwDestroyWindow ( window );

    window = glfwCreateWindow ( WIN_WIDTH, WIN_HEIGHT, "AWengine", primary_monitor, nullptr );

    glfwMakeContextCurrent ( window );
    glfwSetInputMode ( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback ( window, framebuffer_callback );
    glfwSetCursorPosCallback ( window, mouse_position_callback );

}
#include "AWengine.hpp"

int main ( void ){

    GLFW_INIT_LIB

    Window window;

    GLAD_INIT_LIB

    glEnable ( GL_DEPTH_TEST );

    Camera camera;

    // Objects
    Object cube ( "test_obj_files/cube.obj", "shaders/vertex.txt", "shaders/fragment.txt" );

    while ( !glfwWindowShouldClose(window.window) ) {

        glClearColor ( 0.757f, 0.635f, 0.553f, 1.0f );
        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        cube.draw_object ( camera.view, camera.projection );

        glfwSwapBuffers ( window.window );
        glfwPollEvents ( );
    }

    glfwDestroyWindow ( window.window );
    glfwTerminate ( );
    
    return 0;
}
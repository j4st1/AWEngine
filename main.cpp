#include "engine/engine.hpp"

int main ( void ) {

    ENGINE_INIT
    //window.setWindowResolution ( 1280, 1024 );

    // Camera & Camera settings
    Camera  camera;
    camera.setAspectRatio ( window.ASPECT_RATIO );
    double  cameraSensitivity = 0.01;

    // Objects
    Object  cube ( "test_obj_files/cube.obj", "engine/shaders/vertex.txt", "engine/shaders/fragment.txt" );
    Object  cube1 ( "test_obj_files/cube.obj", "engine/shaders/vertex.txt", "engine/shaders/fragment.txt" );
    Object  plane ( "test_obj_files/plane.obj", "engine/shaders/vertex.txt", "engine/shaders/fragment.txt" );

    cube1.setObjectPosition ( 5.0, 3.0, -3.0 );
    plane.setObjectPosition ( 5.0, -3.0, 0.0 );

    while ( !glfwWindowShouldClose ( window.window ) ) {

        glClearColor ( 0.757f, 0.635f, 0.553f, 1.0f );
        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


        camera.cameraSensitivity = cameraSensitivity * deltaTime ( );
        camera.cameraMovement ( window.cursorPos, window.lastCursorPos );

        cube.drawObject ( camera.view, camera.projection );
        cube1.drawObject ( camera.view, camera.projection );
        plane.drawObject ( camera.view, camera.projection );

        glfwSwapBuffers ( window.window );
        glfwPollEvents ( );
        
    }

    glfwDestroyWindow ( window.window );
    glfwTerminate ( );
    
    return 0;
}

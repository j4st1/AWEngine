#include "engine/engine.hpp"

int main ( void ) {

    ENGINE_INIT
    //window.setWindowResolution ( 1280, 1024 );

    // Camera & Camera settings
    Camera  camera;
    camera.aspectRatio = window.ASPECT_RATIO;
    double  cameraSensitivity = 1.8;

    // Objects
    //Object  cube  ( "test_obj_files/cube.obj", "engine/shaders/vertex.glsl", "engine/shaders/fragment.glsl" );
    //Object  cube1  ( "test_obj_files/cube.obj", "engine/shaders/vertex.glsl", "engine/shaders/fragment.glsl" );
    //Object  plane  ( "test_obj_files/plane.obj", "engine/shaders/vertex.glsl", "engine/shaders/fragment.glsl" );
    Object  bmw  ( "test_obj_files/bmw_m3.obj", "engine/shaders/vertex.glsl", "engine/shaders/fragment.glsl" );

    bmw.setObjectPosition ( 0.0, 0.0, 0.0 );
    //cube1.setObjectPosition  ( 5.0, 3.0, -3.0 );
    //plane.setObjectPosition  ( 5.0, -3.0, 0.0 );

    while  ( !glfwWindowShouldClose ( window.window ) ) {

        glClearColor  ( 0.757f, 0.635f, 0.553f, 1.0f );
        glClear  ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        if  ( glfwGetKey ( window.window, GLFW_KEY_F ) == GLFW_PRESS ) camera.setFov ( 120 ); else camera.setFov ( 70 );

        camera.cameraSensitivity = cameraSensitivity * deltaTime  ( );
        camera.cameraMovement  ( &window.cursorPos, &window.lastCursorPos );

        bmw.drawObject ( camera.view, camera.projection );
        //cube.drawObject  ( camera.view, camera.projection );
        //cube1.drawObject  ( camera.view, camera.projection );
        //plane.drawObject  ( camera.view, camera.projection );

        glfwSwapBuffers  ( window.window );
        glfwPollEvents  ( );
        
    }

    //cube.delete_buffers  ( );
    //cube1.delete_buffers  ( );
    bmw.delete_buffers ( );

    glfwDestroyWindow  ( window.window );
    glfwTerminate  ( );
    
    return 0;
}

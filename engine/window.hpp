// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Window for creating window, get cursor position and etc.             //
//                                                                                      //        
// ************************************************************************************ //


#pragma once

#include "../thirdparty/GLFW3/include/GLFW/glfw3.h"
#include "../thirdparty/GLM/glm/glm.hpp"
#include <iostream>

class Window {
    public:
        GLFWwindow*  window;
        GLFWmonitor*  primary_monitor = glfwGetPrimaryMonitor ( );
        const  GLFWvidmode*  mode = glfwGetVideoMode ( primary_monitor );
        GLFWcursor* window_cursor = glfwCreateStandardCursor ( GLFW_CROSSHAIR_CURSOR );

    private:
        inline int  static WIN_WIDTH = 0;
        inline int  static WIN_HEIGHT = 0;

    public:
        double  ASPECT_RATIO = 0.0;
        inline  static  glm::vec2  centredCursorPos;
        inline  static  glm::vec2  lastCursorPos;
        inline  static  glm::vec2  cursorPos;
        inline  static  glm::vec2  cameraCursorPos;

    public:
        Window ( ) {
            
            WIN_WIDTH = mode -> width;
            WIN_HEIGHT = mode -> height;
            ASPECT_RATIO = ( double ) WIN_WIDTH / ( double ) WIN_HEIGHT;

            centredCursorPos.x = ( double ) WIN_WIDTH / 2.0;
            centredCursorPos.y = ( double ) WIN_HEIGHT / 2.0;

            lastCursorPos.x = ( double ) WIN_WIDTH / 2.0;
            lastCursorPos.y = ( double ) WIN_HEIGHT / 2.0;

            cursorPos.x = ( double ) WIN_WIDTH / 2.0;
            cursorPos.y = ( double ) WIN_HEIGHT / 2.0;

            create_window ( );
        }

        Window ( int WINDOW_WIDTH, int WINDOW_HEIGHT ) {

            WIN_WIDTH = WINDOW_WIDTH;
            WIN_HEIGHT = WINDOW_HEIGHT;
            ASPECT_RATIO = ( double ) WIN_WIDTH / ( double ) WIN_HEIGHT;

            lastCursorPos.x = ( double ) WIN_WIDTH / 2.0;
            lastCursorPos.y = ( double ) WIN_HEIGHT / 2.0;

            cursorPos.x = ( double ) WIN_WIDTH / 2.0;
            cursorPos.y = ( double ) WIN_HEIGHT / 2.0;

            create_window ( WIN_WIDTH, WIN_HEIGHT );
        }

        //Window( int window_width, int window_height, int window_mode);

        ~Window ( ) = default;

    public:
        // callback funcs
        static  void  framebuffer_callback ( GLFWwindow* window, int width, int height );
        static  void  mouse_position_callback ( GLFWwindow* window, double xpos, double ypos );

        // funcs
        void  setWindowResolution ( int WIN_WIDTH, int WIN_HEIGHT );

        void  create_window ( void );
        void  create_window ( int window_width, int window_height );
        //void create_window( int window_width, int window_height, int window_mode );

        void  windowFullscreenToggle ( void );
};

// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Window for creating window, get cursor position and etc.             //
//                                                                                      //        
// ************************************************************************************ //


#pragma once

#include "../thirdparty/GLFW3/include/GLFW/glfw3.h"
#include <iostream>

class Window {
    public:
        GLFWwindow*  window;
        GLFWmonitor*  primary_monitor = glfwGetPrimaryMonitor ( );
        const GLFWvidmode*  mode = glfwGetVideoMode ( primary_monitor );

    private:
        int  win_width = 0;
        int  win_height = 0;

        static double last_cursor_xpos;
        static double last_cursor_ypos;

    public:
        static double  cursor_xpos;
        static double  cursor_ypos;

        static double  camera_cursor_xpos;
        static double  camera_cursor_ypos;

    public:
        Window ( ) {
            
            win_width = mode -> width;
            win_height = mode -> height;

            last_cursor_xpos = win_width / 2.0;
            last_cursor_ypos = win_height / 2.0;

            cursor_xpos = 0.0;
            cursor_ypos = 0.0;

            create_window ( );
        }

        Window ( int window_width, int window_height ) {

            win_width = window_width;
            win_height = window_height;

            last_cursor_xpos = win_width / 2.0;
            last_cursor_ypos = win_height / 2.0;

            cursor_xpos = 0.0;
            cursor_ypos = 0.0;

            create_window( win_width, win_height );
        }

        //Window( int window_width, int window_height, int window_mode);

        ~Window ( ) { };

    public:
        // callback funcs
        static void framebuffer_callback ( GLFWwindow* window, int width, int height );
        static void mouse_position_callback ( GLFWwindow* window, double xpos, double ypos );

        // funcs
        void set_window_resolution ( int window_width, int window_height );

        void create_window ( void );
        void create_window ( int window_width, int window_height );
        //void create_window( int window_width, int window_height, int window_mode );

        void window_fullscreen_toggle ( void );
};

#pragma once

#include "AWEngineIncludeLibs.hpp"

#include "engine_config.hpp"

#include <iostream>
#include <cstdlib>

class AWEngineWindow {

    // Variables
    public:
        GLFWwindow *window;
        GLFWmonitor *primary_monitor;
        const GLFWvidmode *mode;

        double cursor_last_x_pos = WIDTH_SCREEN / 2.0;
        double cursor_last_y_pos = HEIGHT_SCREEN / 2.0;

        static double cursor_x_pos;
        static double cursor_y_pos;

    // Constructor
    public:
        AWEngineWindow() {
            create_window();
        }

        ~AWEngineWindow(){}

    // funcs
    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        void create_window();
        static void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos);

    public:
        void window_fullscreen_toggle();
        void GetCursorPosition();
};

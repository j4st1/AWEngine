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

    // struct

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
    public:
        void window_fullscreen_toggle();

};

#pragma once

#include "AWEngineIncludeLibs.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>

class AWEngineObject {

    // Variables
    private:
        unsigned int vertex_shader;
        unsigned int fragment_shader;
        
        char* vertex_src;
        char* fragment_src;
        const char* path_to_vertex_shdr_src = "shaders/vertex.txt";
        const char* path_to_fragment_shdr_src = "shaders/fragment.txt";

        unsigned int VBO = 0;
        unsigned int VAO = 0;
        unsigned int EBO = 0;
        unsigned int shader_program = 0;

        char* obj_src;
        const char* path_to_object;

    public:
        std::vector<float> v;
        std::vector<float> vt;
        std::vector<float> vn;
        std::vector<int> f;

        float object_xpos;
        float object_ypos;
        float object_zpos;

        float camera_xpos;
        float camera_ypos;
        float camera_zpos;

    private:
        glm::vec3 camera_pos;
        glm::vec3 camera_target;
        glm::vec3 camera_direction;
        float camera_speed;
        glm::vec3 camera_front;
        glm::vec3 up;
        glm::vec3 camera_right;
        glm::vec3 camera_up;

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view;
        glm::mat4 projection;

    // Constructor & Destructor
    public:
        AWEngineObject(const char* path_to_obj){

            path_to_object = path_to_obj;

            obj_parser();
            create_shader_program();
        }
        ~AWEngineObject() {}

    // Funcs
    private:
        char* read_file(const char* filename);
        std::vector<std::string> split(std::string& str, char split_char);
        void obj_parser();
        void create_shader_program();

    public:
        void set_camera_pos(glm::vec3 cam_pos, glm::vec3 camera_target);
        void camera_movement(float* speed, GLFWwindow* window);
        void draw_object();
        void disable_object();
};

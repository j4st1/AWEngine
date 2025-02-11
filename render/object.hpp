// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Object for create object, funcs for object control( mat, pos, etc ). //
//                                                                                      //
// ************************************************************************************ //


#pragma once

#include "shader.hpp"
#include "camera.hpp"

class Object : public Shader {
    public:
        double  object_x_pos = 0.0;
        double  object_y_pos = 0.0;
        double  object_z_pos = 0.0;
        glm::vec3  object_position;
        glm::mat4  model;

    public:
        Object ( const char* path_to_obj_file, const char* path_to_vertex_shader, const char* path_to_fragment_shader) : Shader ( path_to_obj_file, path_to_vertex_shader, path_to_fragment_shader ) {

            model = glm::mat4 ( 1.0 );
            object_position = glm::vec3 ( object_x_pos, object_y_pos, object_z_pos );
            model = glm::translate ( model, object_position );

        }
        Object ( const char* path_to_obj_file, const char* path_to_vertex_shader, const char* path_to_fragment_shader, Camera* Camera) : Shader ( path_to_obj_file, path_to_vertex_shader, path_to_fragment_shader ) {
            
            model = glm::mat4 ( 1.0 );
            object_position = glm::vec3 ( object_x_pos, object_y_pos, object_z_pos );
            model = glm::translate ( model, object_position );

        }
        ~Object ( ) { };

    public:
        void set_object_position ( double object_x_pos, double object_y_pos, double object_z_pos );
        void draw_object ( glm::mat4 view, glm::mat4 projection );
};
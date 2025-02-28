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
        glm::vec3  objectPosition = glm::vec3 ( 0.0, 0.0, 0.0 );
        glm::mat4  model = glm::mat4 ( 1.0 );

    public:
        Object ( const char* path_to_obj_file, const char* path_to_vertex_shader, const char* path_to_fragment_shader) : 
        Shader ( path_to_obj_file, path_to_vertex_shader, path_to_fragment_shader ) {
            
            model = glm::translate ( model, objectPosition );

        }
        /*Object ( const char* path_to_obj_file, const char* path_to_vertex_shader, const char* path_to_fragment_shader, Camera* Camera) : 
        Shader ( path_to_obj_file, path_to_vertex_shader, path_to_fragment_shader ) {
            // optionally use Camera

            object_position = glm::vec3(object_x_pos, object_y_pos, object_z_pos);
            model = glm::translate(glm::mat4(1.0), object_position);

        }*/
        ~Object ( ) = default;

    public:
        void setObjectPosition ( double object_x_pos, double object_y_pos, double object_z_pos );
        void drawObject ( glm::mat4& view, glm::mat4& projection );
};

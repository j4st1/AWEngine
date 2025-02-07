// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Shader included tools for creating object with needed shader         //
//                                                                                      //        
// ************************************************************************************ //

#pragma once

#include "../thirdparty/GLAD/include/glad/glad.h"
#include "../devtools/devtools.hpp"
#include <vector>

class Shader {

    public:
        unsigned int  VBO = 0;
        unsigned int  VAO = 0;
        unsigned int  EBO = 0;
        unsigned int  shader_program = 0;
        unsigned int  vertex_shader = 0;
        unsigned int  fragment_shader = 0;

        int  shdr_view_mat_ptr = 0;
        int  shdr_model_mat_ptr = 0;
        int  shdr_projection_mat_ptr = 0;

        char*  vertex_src;
        char*  fragment_src;
        char*  obj_src;

        const char*  path_to_vshader;
        const char*  path_to_fshader;
        const char*  path_to_object_model;

        std::vector <float>  v;
        std::vector <float>  vt;
        std::vector <float>  vn;
        std::vector <unsigned int>  f;

    public:
        Shader ( const char* path_to_object_model, const char* path_to_vshader, const char* path_to_fshader ) {
            
            this -> path_to_object_model = path_to_object_model;
            this -> path_to_vshader = path_to_vshader;
            this -> path_to_fshader = path_to_fshader;

            vertex_src = filereader ( path_to_vshader );
            fragment_src = filereader ( path_to_fshader );

            obj_src = filereader ( path_to_object_model );
            obj_parser ( obj_src, v, vt, vn, f );

            create_shader_program ( );
            bind_buffers ( );

            int view_ptr = glGetUniformLocation ( shader_program, "view" );
            int model_ptr = glGetUniformLocation ( shader_program, "model" );
            int projection_ptr = glGetUniformLocation ( shader_program, "projection" );

        }

        ~Shader ( ) { };

    private:
        void create_shader_program ( void );
        void bind_buffers ( void );
};
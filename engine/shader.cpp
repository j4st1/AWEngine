// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Shader included tools for creating object with needed shader         //
//                                                                                      //        
// ************************************************************************************ //


#include "shader.hpp"

void Shader::create_shader_program( void ) {

    shader_program = glCreateProgram ( );

    unsigned  int  vertex_shader = glCreateShader ( GL_VERTEX_SHADER );
    glShaderSource ( vertex_shader, 1, &vertex_src, NULL );
    glCompileShader ( vertex_shader );

    // vertex shader compilation test
    int  success;
    char  func_info_log [ 512 ];
    glGetShaderiv ( vertex_shader, GL_COMPILE_STATUS, &success );
    if ( !success ) {
        glGetShaderInfoLog ( vertex_shader, 512, NULL, func_info_log );
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << func_info_log << "\n";
    }

    unsigned int fragment_shader = glCreateShader ( GL_FRAGMENT_SHADER );
    glShaderSource ( fragment_shader, 1, &fragment_src, NULL );
    glCompileShader ( fragment_shader );

    // fragment shader compilation test
    glGetShaderiv ( fragment_shader, GL_COMPILE_STATUS, &success );
    if ( !success ) {

        glGetShaderInfoLog ( fragment_shader, 512, NULL, func_info_log );
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << func_info_log << "\n";

    }

    glAttachShader ( shader_program, vertex_shader );
    glAttachShader ( shader_program, fragment_shader );
    glLinkProgram ( shader_program );

    // Link
    glGetProgramiv ( shader_program, GL_LINK_STATUS, &success );
    if ( !success ) {

        glGetProgramInfoLog ( shader_program, 512, NULL, func_info_log );
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << func_info_log << "\n";

    }

    glDeleteShader ( vertex_shader );
    glDeleteShader ( fragment_shader );

    std::cout << "Create shader_program is done" << std::endl;

}

void Shader::bind_buffers ( void ) {

    glGenVertexArrays ( 1, &VAO );
    glGenBuffers ( 1, &VBO );
    glGenBuffers ( 1, &EBO );

    glBindVertexArray ( VAO );
    glBindBuffer ( GL_ARRAY_BUFFER, VBO );
    glBufferData ( GL_ARRAY_BUFFER, v.size() * sizeof ( float ), v.data(), GL_STATIC_DRAW );
    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData ( GL_ELEMENT_ARRAY_BUFFER, f.size ( ) * sizeof ( unsigned int ), f.data ( ), GL_STATIC_DRAW );
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof ( float ), NULL );
    glEnableVertexAttribArray ( 0 );
    glBindBuffer ( GL_ARRAY_BUFFER, 0 );
    glBindVertexArray ( 0 );
    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, 0 );

    std::cout << "buffers bind is done" << std::endl;
    
}
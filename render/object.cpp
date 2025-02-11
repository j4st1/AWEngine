// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Object for create object, funcs for object control( mat, pos, etc).  //
//                                                                                      //        
// ************************************************************************************ //


#include "object.hpp"

void Object::set_object_position ( double object_x_pos, double object_y_pos, double object_z_pos ) {

    this -> object_x_pos = object_x_pos;
    this -> object_y_pos = object_y_pos;
    this -> object_z_pos = object_z_pos;

}

void Object::draw_object ( glm::mat4 view, glm::mat4 projection ) { 
    
    glUseProgram ( shader_program );

    glUniformMatrix4fv ( Shader::shdr_model_mat_ptr, 1, GL_FALSE, glm::value_ptr ( model ) );

    glUniformMatrix4fv ( Shader::shdr_view_mat_ptr, 1, GL_FALSE, glm::value_ptr ( view) );

    glUniformMatrix4fv ( Shader::shdr_projection_mat_ptr, 1, GL_FALSE, glm::value_ptr ( projection ) );

    glBindVertexArray ( VAO );
    glDrawElements ( GL_TRIANGLES, f.size(), GL_UNSIGNED_INT, 0 );

}
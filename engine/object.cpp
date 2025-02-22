// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Object for create object, funcs for object control( mat, pos, etc).  //
//                                                                                      //        
// ************************************************************************************ //


#include "object.hpp"

void Object::setObjectPosition ( double object_x_pos, double object_y_pos, double object_z_pos ) {
    
    // Тестовый вариант
    objectPosition = glm::vec3 ( object_x_pos, object_y_pos, object_z_pos );
    model = glm::translate ( glm::mat4(1.0), objectPosition );

}

void Object::drawObject ( glm::mat4 view, glm::mat4 projection ) { 
    
    glUseProgram ( shader_program );

    glUniformMatrix4fv ( Shader::shdr_model_mat_ptr, 1, GL_FALSE, glm::value_ptr ( model ) );

    glUniformMatrix4fv ( Shader::shdr_view_mat_ptr, 1, GL_FALSE, glm::value_ptr ( view ) );

    glUniformMatrix4fv ( Shader::shdr_projection_mat_ptr, 1, GL_FALSE, glm::value_ptr ( projection ) );

    glBindVertexArray ( VAO );
    
    glDrawElements ( GL_TRIANGLES, f.size(), GL_UNSIGNED_INT, 0 );

}
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

void Object::draw_object ( void ) { 
    
    glUseProgram ( shader_program );

    glUniformMatrix4fv(model_ptr, 1, GL_FALSE, glm::value_ptr(Camera::model));

    glUniformMatrix4fv(view_ptr, 1, GL_FALSE, glm::value_ptr(Camera::view));

    glUniformMatrix4fv(projection_ptr, 1, GL_FALSE, glm::value_ptr(Camera::projection));

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, f.size(), GL_UNSIGNED_INT, 0);

}
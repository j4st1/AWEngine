// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose:                                                                            //
//                                                                                      //
// ************************************************************************************ //


#include "camera.hpp"

// Camera settings

void Camera::set_camera_settings ( glm::vec3 camera_pos, glm::vec3 camera_target, double camera_speed, double camera_sensitivity ) {

    this -> camera_pos = camera_pos;
    this -> camera_target = camera_target;

    this -> camera_speed = camera_speed;
    this -> camera_sensitivity = camera_sensitivity;

}

void Camera::camera_movement ( void ) {

    
}
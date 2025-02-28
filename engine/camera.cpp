// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Camera                                                               //
//                                                                                      //
// ************************************************************************************ //


#include "camera.hpp"

// Camera settings

void Camera::setCameraSettings ( glm::vec3 cameraPos, glm::vec3 cameraTarget, double cameraSensitivity ) {

    this -> cameraPos = cameraPos;
    this -> cameraTarget = cameraTarget;
    this -> cameraSensitivity = cameraSensitivity;

}


// Camera movement

void Camera::cameraMovement ( glm::vec2* cursorPos, glm::vec2* lastCursorPos ) {

    /*std::cout << "cursor_x_pos: " << cursorPos -> x << std::endl;
    std::cout << "cursor_y_pos: " << cursorPos -> y << std::endl;
    std::cout << "last_cursor_xpos: " << lastCursorPos -> x << std::endl;
    std::cout << "last_cursor_ypos: " << lastCursorPos -> y << std::endl;*/

    // Calculate offsets
    offset.x = ( cursorPos -> x - lastCursorPos -> x ) * cameraSensitivity;
    offset.y = ( lastCursorPos -> y - cursorPos -> y ) * cameraSensitivity;
    //std::cout << "xoffset: " << offset.x << " yoffset: " << offset.y << std::endl;

    // Update yaw and pitch
    angles.x += offset.x;
    angles.y += offset.y;
    //std::cout << "Yaw: " << angles.x << " Pitch: " << angles.y << std::endl;

    if ( angles.y >  89.0 ) angles.y = 89.0;
    if ( angles.y < -89.0 ) angles.y = -89.0;

    cameraFront.x = cos ( glm::radians ( angles.x ) ) * cos ( glm::radians ( angles.y ) );
    cameraFront.y = sin ( glm::radians ( angles.y ) );
    cameraFront.z = sin ( glm::radians ( angles.x ) ) * cos ( glm::radians ( angles.y ) );
    cameraFront = glm::normalize ( cameraFront );
    //std::cout << "Camera Front: " << cameraFront.x << " " << cameraFront.y << " " << cameraFront.z << std::endl;

    // Update the view matrix
    view = glm::lookAt ( cameraPos, cameraPos + cameraFront, cameraUp );

    //std::cout << "Camera Pos: " << cameraPos.x << " " << cameraPos.y << " " << cameraPos.z << std::endl;

    lastCursorPos -> x = cursorPos -> x;
    lastCursorPos -> y = cursorPos -> y;

}

void  Camera::setFov  ( int  fov ) { 

    this -> fov = fov;
    projection = glm::perspective ( glm::radians ( ( double ) fov ), 1920.0 / 1080.0 , 0.1, 100.0 );

}

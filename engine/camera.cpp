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

void Camera::cameraMovement ( glm::vec2 cursorPos, glm::vec2 lastCursorPos ) {

    std::cout << "cursor_x_pos: " << cursorPos.x << std::endl;
    std::cout << "cursor_y_pos: " << cursorPos.y << std::endl;
    std::cout << "last_cursor_xpos: " << lastCursorPos.x << std::endl;
    std::cout << "last_cursor_ypos: " << lastCursorPos.y << std::endl;

    // Calculate offsets
    offset.x = cursorPos.x - lastCursorPos.x;
    offset.y = lastCursorPos.y - cursorPos.y;

    // Update last cursor positions
    lastCursorPos.x = cursorPos.x;
    lastCursorPos.y = cursorPos.y;

    offset.x *= cameraSensitivity;
    offset.y *= cameraSensitivity;

    // Update yaw and pitch
    angles.x += offset.x;
    angles.y += offset.y;

    if ( angles.y > 89.0 ) angles.y = 89.0;
    if ( angles.y < -89.0 ) angles.y = -89.0;

    radAngles.x = glm::radians ( angles.x );
    radAngles.y = glm::radians ( angles.y );

    cameraFront.x = cos ( radAngles.x ) * cos ( radAngles.y );
    cameraFront.y = sin ( radAngles.y );
    cameraFront.z = sin ( radAngles.x ) * cos ( radAngles.y );
    cameraFront = glm::normalize ( cameraFront );

    // Update the view matrix
    view = glm::lookAt ( cameraPos, cameraPos + cameraFront, cameraUp );

    std::cout << "Camera Pos: " << cameraPos.x << " " << cameraPos.y << " " << cameraPos.z << std::endl;
    std::cout << "Camera Front: " << cameraFront.x << " " << cameraFront.y << " " << cameraFront.z << std::endl;
    std::cout << "Yaw: " << angles.x << " Pitch: " << angles.y << std::endl;
    std::cout << "xoffset: " << offset.x << " yoffset: " << offset.y << std::endl;

}
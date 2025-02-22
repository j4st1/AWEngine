// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: class Camera                                                               //
//                                                                                      //
// ************************************************************************************ //

#pragma once 

#include "../thirdparty/GLM/glm/glm.hpp"
#include "../thirdparty/GLM/glm/gtc/matrix_transform.hpp"
#include "../thirdparty/GLM/glm/gtc/type_ptr.hpp"

#include "../thirdparty/GLFW3/include/GLFW/glfw3.h"

#include <iostream>


class Camera {

    public:
        glm::vec3  cameraPos = glm::vec3 ( 0.0, 0.0, 5.0 );
        glm::vec3  cameraTarget = glm::vec3 ( 0.0, 0.0, 0.0 );
        glm::vec3  cameraDirection = glm::normalize ( cameraPos - cameraTarget );
        double  cameraSensitivity = 0.0;

        glm::vec2  angles = glm::vec2 ( 0.0, 0.0 );
        glm::vec2  radAngles = glm::vec2 ( 0.0, 0.0 );
        glm::vec2  offset = glm::vec2 ( 0.0, 0.0 );
        double aspectRatio = 0.0;

    private:
        bool firstMouse = true;

    private:
        glm::vec3  cameraFront = glm::vec3 ( 0.0, 0.0, -1.0 );
        glm::vec3  cameraRight = glm::normalize ( glm::cross ( glm::vec3 ( 0.0, 1.0, 0.0 ), cameraDirection ) );
        glm::vec3  cameraUp = glm::cross ( cameraDirection, cameraRight );

    public:
        glm::mat4  view = glm::lookAt ( cameraPos, cameraPos + cameraFront, cameraUp );
        glm::mat4  projection = glm::perspective ( glm::radians ( 45.0 ), 1920.0 / 1080.0, 0.1, 100.0 );

    public:
        Camera ( ) { }   

        ~Camera ( ) = default;

    private:
        
        
    public:
        void  setCameraSettings ( glm::vec3 cameraPos, glm::vec3 cameraTarget, double cameraSensitivity );
        void  cameraMovement ( glm::vec2 cursorPos, glm::vec2 lastCursorPos );
        inline void  setAspectRatio ( double aspectRatio ) { this -> aspectRatio = aspectRatio; }
    
};

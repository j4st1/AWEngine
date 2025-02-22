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

class Camera {

    public:
        glm::vec3  camera_pos;
        glm::vec3  camera_target;
        glm::vec3  camera_direction;
        double  camera_speed;
        double  camera_sensitivity;
        double  yaw;
        double  pitch;

    private:
        glm::vec3  camera_front;
        glm::vec3  up;
        glm::vec3  camera_right;
        glm::vec3  camera_up;

    public:
        glm::mat4  model;
        glm::mat4  view;
        glm::mat4  projection;

    public:
        Camera ( ) {

            yaw = 0.0;
            pitch = 0.0;

            camera_pos = glm::vec3 ( 0.0f, 0.0f, 0.0f );
            camera_target = glm::vec3 ( 0.0f, 0.0f, 0.0f );
            camera_direction = glm::normalize ( camera_pos - camera_target );

            up = glm::vec3 ( 0.0f, 0.0f, 0.0f );
            camera_right = glm::normalize ( glm::cross ( up, camera_direction ) );
            camera_up = glm::cross ( camera_direction, camera_right );
            camera_front = glm::vec3 ( 0.0f, 0.0f, 0.0f );
            

            model = glm::mat4 ( 1.0f );
            view =  glm::lookAt ( camera_pos, camera_pos + camera_front, camera_up );
            projection = glm::perspective ( glm::radians (45.0f), 800.0f / 600.0f, 0.1f, 100.0f );

        }   

        ~Camera ( ) { }

    private:
        
        
    public:
        void set_camera_settings ( glm::vec3 camera_pos, glm::vec3 camera_target, double camera_speed, double camera_sensitivity );
        void camera_movement ( void );
}; 
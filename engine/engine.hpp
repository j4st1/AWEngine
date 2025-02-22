// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: include all engine functions                                               //
//                                                                                      //        
// ************************************************************************************ //

#pragma once

#include "../thirdparty/GLAD/include/glad/glad.h"
#include "window.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "object.hpp"
#include "engineTools.hpp"

#define  ENGINE_INIT  if ( !glfwInit ( ) ) { std::cout << "Failed to initialize GLFW\n"; exit ( -1 ); } \
                      Window window; \
                      if ( !gladLoadGLLoader ( ( GLADloadproc ) glfwGetProcAddress) ) { std::cout << "Failed to initialize GLAD\n"; exit ( -1); } \
                      glEnable ( GL_DEPTH_TEST ); 

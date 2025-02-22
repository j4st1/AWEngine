// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: header file it's included funcs of engine                                  //
//                                                                                      //        
// ************************************************************************************ //

#include "thirdparty/GLAD/include/glad/glad.h"
#include "render/window.hpp"
#include "render/object.hpp"

#define GLFW_INIT_LIB if ( !glfwInit ( ) ) { std::cout << "Failed to initialize GLFW\n"; exit ( -1 );}
#define GLAD_INIT_LIB if ( !gladLoadGLLoader ( ( GLADloadproc ) glfwGetProcAddress) ) { std::cout << "Failed to initialize GLAD\n"; exit ( -1); }
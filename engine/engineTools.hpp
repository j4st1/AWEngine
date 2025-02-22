// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: tools for engine such as read file, split for obj parser, obj parser etc.  //
//                                                                                      //        
// ************************************************************************************ //


#pragma  once

#include  <iostream>
#include  <sstream>
#include  <cstring>
#include  <string>
#include  <cstdlib>
#include  <vector>

#include  "../thirdparty/GLFW3/include/GLFW/glfw3.h"

char*  fileReader  ( const char* filename );

std::vector<std::string>  split  ( std::string& str, char split_char );

void  objParser  ( char* obj_src, std::vector<float>& v, std::vector<float>& vt, std::vector<float>& vn, std::vector<unsigned int>& f );

double  deltaTime  ( );
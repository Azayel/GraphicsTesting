#pragma once
#include <string>
#include <GL/gl.h>

struct Shader{
  
  Shader(const std::string , const std::string );
  void checkError(GLuint);
};

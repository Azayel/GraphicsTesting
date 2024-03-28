#pragma once
#include <string>

struct Shader{
  
  Shader(const std::string , const std::string );
  void checkError(GLuint);
};

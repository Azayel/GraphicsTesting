#pragma once
#include <string>
#include <GL/gl.h>

enum ShaderType{
  Shader,
  Program,
};


struct ShaderStruct{
  
  ShaderStruct(const std::string, const std::string);
  ~ShaderStruct();
  void checkCompilationErrors(GLuint, ShaderType);

private:
  GLuint ShaderID;
};

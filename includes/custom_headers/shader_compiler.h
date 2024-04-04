#pragma once
#include <string>
#include <glad/glad.h>

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

#pragma once
#include<custom_headers/glCommon.h>
#include <iostream>
#include <string>

enum ShaderType{
  Shader,
  Program,
};


struct ShaderStruct{
private:
    GLuint ShaderID;
public:
  ShaderStruct(const std::string, const std::string);
  ~ShaderStruct(){
      std::cout << "Deleting Shader" << std::endl;
      glDeleteProgram(ShaderID);
  }
  void checkCompilationErrors(GLuint, ShaderType);

};

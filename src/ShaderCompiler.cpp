#include <cstddef>
#include <custom_headers/shader_compiler.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>

ShaderStruct::ShaderStruct(const std::string vertexPath, const std::string FragmentPath){
  std::cout << "Constructor\n"; 
  std::ifstream VertexFile;
  std::ifstream FragmentFile;
  std::string vertexShaderString;
  std::string fragmentShaderString;
  
  try {
    VertexFile.open(vertexPath, std::ifstream::in);
    FragmentFile.open(FragmentPath, std::ifstream::in);
    std::stringstream vStream;
    std::stringstream fStream;
    vStream << VertexFile.rdbuf();
    fStream << FragmentFile.rdbuf();
    VertexFile.close();
    FragmentFile.close();
    vertexShaderString = vStream.str();
    fragmentShaderString = fStream.str();

  } catch (std::ios_base::failure &e) {
    std::cerr << e.what() << std::endl;
  }
  

  //glCreateShader requires a const char string
  const char* vertexShaderCode = vertexShaderString.c_str();
  const char* fragmentShaderCode = fragmentShaderString.c_str();
  
  //ShaderIDs
  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  

  glShaderSource(vertexShaderID,1, &vertexShaderCode,NULL);
  glShaderSource(fragmentShaderID,1,&fragmentShaderCode,NULL);
  
  glCompileShader(vertexShaderID);
  checkCompilationErrors(vertexShaderID, ShaderType::Shader);
  glCompileShader(fragmentShaderID);
  checkCompilationErrors(fragmentShaderID, ShaderType::Shader);
  //Ataching the Shader to the Program ID
  ShaderID = glCreateProgram();
  glAttachShader(ShaderID,vertexShaderID);
  glAttachShader(ShaderID,fragmentShaderID);
  checkCompilationErrors(ShaderID, ShaderType::Program);

  glDeleteShader(vertexShaderID);
  glDeleteShader(fragmentShaderID);
}

ShaderStruct::~ShaderStruct(){
  std::cout << "Deleting Shader" << std::endl;
  glDeleteProgram(ShaderID);
}


void ShaderStruct::checkCompilationErrors(GLuint shaderType, ShaderType type){

  if(type == ShaderType::Shader){
    GLint success = 0;
    glGetShaderiv(shaderType, GL_COMPILE_STATUS, (int *)&success);
    if(success == GL_FALSE){
      GLint maxLength= 0;
      glGetShaderiv(shaderType, GL_INFO_LOG_LENGTH,&maxLength);
      GLchar infoLog[maxLength];
      glGetShaderInfoLog(shaderType,maxLength,&maxLength, infoLog);
      std::cout << "ERROR::SHADER_COMPILATION_ERROR \n"
        << infoLog
        << "\n --------------------------------------"
        << std::endl;


    }
  }else if(type == ShaderType::Program){
    GLint isLinked = 0;
    glGetProgramiv(shaderType, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE){
      GLint maxLength = 0;
      glGetProgramiv(shaderType, GL_INFO_LOG_LENGTH, &maxLength);
      GLchar infoLog[maxLength];
      glGetProgramInfoLog(shaderType,maxLength,&maxLength,infoLog);
      
      std::cout << "ERROR::PROGRAM_LINKING_ERROR \n"
        << infoLog
        << "\n --------------------------------------"
        << std::endl;

    }
  }
}


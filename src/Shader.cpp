#include <cstddef>
#include <custom_headers/shader_compiler.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>

Shader::Shader(const std::string vertexPath, const std::string FragmentPath){
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

  const char* vertexShaderCode = vertexShaderString.c_str();
  const char* fragmentShaderCode = fragmentShaderString.c_str();

  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(vertexShaderID,1, &vertexShaderCode,NULL);
  glShaderSource(fragmentShaderID,1,&fragmentShaderCode,NULL);
  glCompileShader(vertexShaderID);
  glCompileShader(fragmentShaderID);
}


Shader::checkError(GLuint shaderType){
  GLuint success = 0;
  glGetShaderiv(shaderType, GL_COMPILE_STATUS, &success);
  if(success == GL_FALSE){
    std::cout << "Failed Compilation\n";
  }
}


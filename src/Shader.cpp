#include <custom_headers/shader_compiler.h>
#include <fstream>
#include <iostream>
#include <sstream>

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

  std::cout << vertexShaderString << std::endl;
  std::cout << fragmentShaderString << std::endl;
}


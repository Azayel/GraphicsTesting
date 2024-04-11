#pragma once
#include <custom_headers/glCommon.h>
#include <vector>
#include <glm/glm.hpp>


class Triangle{
  GLuint VBO,VAO;
  std::vector<glm::vec3> vectices;

  


public:
  Triangle();
};

#include <custom_headers/triangleRenderer.h>

Triangle::Triangle(){
  glad_glGenBuffers(1,&VBO);
  glad_glGenVertexArrays(1,&VAO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

}

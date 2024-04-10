#include <custom_headers/triangleRenderer.h>

Triangle::Triangle(){
  glad_glGenBuffers(1,&VBO);
  glad_glGenVertexArrays(1,&VAO);

}

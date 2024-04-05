#include <custom_headers/shader_compiler.h>

#include <cstdint>
#include <cstdlib>
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <memory>
#include <stdexcept>


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;


struct Application{
  public:
  void run(){
    GLinit();
    ShaderInit();
    mainLoop();
    cleanup();
  }
  private:
  GLFWwindow* window;
  std::unique_ptr<ShaderStruct> shader_ptr;
  void ShaderInit(){
    shader_ptr = std::unique_ptr<ShaderStruct>(new ShaderStruct{"../resources/fragmentShader.glsl", "../resources/vertexshader.glsl"});
  }

  void GLinit(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "Visualizer", nullptr, nullptr);

    if(window == nullptr) {
      throw std::runtime_error{"Failled to Create GLFW Window!"};
    }
    glfwMakeContextCurrent(window);

    //Enter Callbacks here
    //

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
      throw std::runtime_error{"Failed to initialize GLAD"};
    }
  }

  void mainLoop(){
    while(!glfwWindowShouldClose(window)){
    }
  }
  
  void cleanup(){
    glfwTerminate();
  }
};






int main(){
  Application app{};

  try{
    app.run();

  } catch (const std::exception& e){
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
  

}

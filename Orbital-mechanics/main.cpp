#define GLFW_INCLUDE_NONE
#include <math.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
// soul class (using for objects that move and interact with eachother later) (these are doing nothing until much later)
class soul {
    private:
    double speed;
    double acceleration;


};

class values {
    private:
    string windowtitle;

};

int main (int argc, char **argv) {
//initialize glfw
  glfwInit();
//create window
    GLFWwindow* window = glfwCreateWindow(640, 480, "Testing", NULL, NULL); 
  
    if (!window){
      return 0;
      }

    //context
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwTerminate();

    //window close flag
    while(!glfwWindowShouldClose) {
      //keep doing shit
    }
  }



#include "environment.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace cp {
int width = 0;
int height = 0;
namespace core {

Environment::Environment() {}
Environment::~Environment() {}
GLFWwindow* Environment::size(int width, int height) {
  auto window =
      glfwCreateWindow(width, height, "cpprocessing", nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Can't create GLFW window." << std::endl;
    return nullptr;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, viewport[2], viewport[3], 0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  cp::width = width;
  cp::height = height;
  return window;
}
}  // namespace core
}  // namespace cp

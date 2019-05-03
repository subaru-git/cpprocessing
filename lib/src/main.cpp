#include "main.hpp"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include "perlinnoise.hpp"

extern void setup();
extern void draw();

namespace cp {
namespace core {

Main::Main() {}

Main::~Main() {}

void Main::size(int width, int height) {
  windows_.push_back(env_.size(width, height));
}

void Main::background(int r, int g, int b, int a) {
  color_.background(r, g, b, a);
}

void Main::point(float x, float y) { shape_.point(x, y, color_); }
void Main::strokeWeight(float weight) { shape_.strokeWeight(weight); }
void Main::stroke(int r, int g, int b, int a) { color_.stroke(r, g, b, a); }
void Main::noStroke() { color_.noStroke(); }
void Main::line(float x1, float y1, float x2, float y2) {
  shape_.line(x1, y1, x2, y2, color_);
}
void Main::beginShape() { shape_.beginShape(color_); }
void Main::vertex(float x, float y) { shape_.vertex(x, y); }
void Main::endShape() { shape_.endShape(); }
void Main::translate(float x, float y) { transform_.translate(x, y); }
void Main::pushMatrix() { transform_.pushMatrix(); }
void Main::popMatrix() { transform_.popMatrix(); }
void Main::rotate(float angle) { transform_.rotate(angle); }
void Main::rect(float x, float y, float w, float h) {
  shape_.rect(x, y, w, h, color_);
}
void Main::fill(int r, int g, int b, int a) { color_.fill(r, g, b, a); }
void Main::noFill() { color_.noFill(); }
void Main::ellipse(float x, float y, float w, float h) {
  shape_.ellipse(x, y, w, h, color_);
}

int Main::start() {
  // initialize glfw
  if (glfwInit() == GL_FALSE) {
    std::cerr << "Can't initialize GLFW" << std::endl;
    return 1;
  }

  atexit(glfwTerminate);
  glfwSetErrorCallback([](int error, const char* description) {
    std::cerr << "[" << error << "]: " << description << std::endl;
  });
  showGLFWVersion();
  PerlinNoise::InitializePerlinNoise();
  setup();

  while (glfwWindowShouldClose(windows_.at(0)) == GL_FALSE) {
    draw();
    glfwSwapBuffers(windows_.at(0));
    transform_.reset();
    glfwWaitEventsTimeout(0.01666666);
  }
  PerlinNoise::TerminatePerlinNoise();
  return 0;
}

void Main::showGLFWVersion() {
  std::cout << "glfw version " << GLFW_VERSION_MAJOR << "."
            << GLFW_VERSION_MINOR << "." << GLFW_VERSION_REVISION << std::endl;
}
}  // namespace core
}  // namespace cp

#include "color.hpp"
#include <GLFW/glfw3.h>

namespace cp {
namespace core {
Color::Color() {}
Color::~Color() {}
void Color::background(int r, int g, int b, int a) {
  glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
void Color::stroke(int r, int g, int b, int a) {
  stroke_ = data::Color{r, g, b, a};
}
void Color::noStroke() { strokeenabled_ = false; }
void Color::fill(int r, int g, int b, int a) {
  fill_ = data::Color{r, g, b, a};
  fillenabled_ = true;
}
void Color::noFill() { fillenabled_ = false; }
const data::Color& Color::getFillColor() const { return fill_; }
const data::Color& Color::getStrokeColor() const { return stroke_; }
bool Color::isFillEnabled() const { return fillenabled_; }
bool Color::isStrokeEnabled() const { return strokeenabled_; }
}  // namespace core
}  // namespace cp

#include "transform.hpp"
#include <GLFW/glfw3.h>
#include "constants.hpp"

namespace cp {
namespace core {
Transform::Transform() {}
Transform::~Transform() {}
void Transform::translate(float x, float y) {
  x_ += x;
  y_ += y;
  glTranslatef(x, y, 0.0f);
}
void Transform::reset() {
  glTranslatef(-x_, -y_, 0.0f);
  x_ = 0.0f;
  y_ = 0.0f;
}
void Transform::pushMatrix() { glPushMatrix(); }
void Transform::popMatrix() { glPopMatrix(); }
void Transform::rotate(float angle) {
  glRotatef(angle * (180.0f / PI), 0.0f, 0.0f, 1.0f);
}
}  // namespace core
}  // namespace cp

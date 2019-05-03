#pragma once

namespace cp {
namespace core {
class Transform {
 public:
  Transform();
  ~Transform();

  void translate(float x, float y);
  void pushMatrix();
  void popMatrix();
  void rotate(float angle);
  void reset();

 private:
  float x_ = 0.0f;
  float y_ = 0.0f;
};
}  // namespace core
}  // namespace cp

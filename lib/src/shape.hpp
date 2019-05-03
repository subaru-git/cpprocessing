#pragma once

namespace cp {
namespace core {
class Color;
class Shape {
 public:
  Shape();
  ~Shape();

  void point(float x, float y, const Color& color);
  void strokeWeight(float weight);
  void line(float x1, float y1, float x2, float y2, const Color& color);
  void beginShape(const Color& color);
  void vertex(float x, float y);
  void endShape();
  void rect(float x, float y, float w, float h, const Color& color);
  void ellipse(float x, float y, float w, float h, const Color& color);

 private:
  float weight_ = 0.0f;
};
}  // namespace core
}  // namespace cp

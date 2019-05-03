/** @file
 * @brief Class @ref Main
 *
 */

#pragma once
#include <vector>
#include "color.hpp"
#include "environment.hpp"
#include "shape.hpp"
#include "transform.hpp"

struct GLFWwindow;

namespace cp {
namespace core {

/**
 * @brief cpprocessing main class. this class has all api.
 */
class Main {
 public:
  Main();
  ~Main();

  int start();
  void size(int width, int height);
  void background(int r, int g, int b, int a);
  void point(float x, float y);
  void strokeWeight(float weight);
  void stroke(int r, int g, int b, int a);
  void noStroke();
  void line(float x1, float y1, float x2, float y2);
  void beginShape();
  void vertex(float x, float y);
  void endShape();
  void translate(float x, float y);
  void pushMatrix();
  void popMatrix();
  void rotate(float angle);
  void rect(float x, float y, float w, float h);
  void fill(int r, int g, int b, int a);
  void noFill();
  void ellipse(float x, float y, float w, float h);

 private:
  Environment env_;
  Color color_;
  Shape shape_;
  Transform transform_;
  std::vector<GLFWwindow*> windows_;

  void showGLFWVersion();
};
}
}

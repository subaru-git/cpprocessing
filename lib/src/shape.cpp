#include "shape.hpp"
#include <GLFW/glfw3.h>
#include <cmath>
#include "color.hpp"
#include "constants.hpp"

namespace cp {
namespace core {
Shape::Shape() {}
Shape::~Shape() {}
void Shape::point(float x, float y, const Color& color) {
  glPointSize(weight_);
  if (color.isStrokeEnabled()) {
    const auto c = color.getStrokeColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
  }
}
void Shape::strokeWeight(float weight) { weight_ = weight; }
void Shape::line(float x1, float y1, float x2, float y2, const Color& color) {
  glLineWidth(weight_);
  if (color.isStrokeEnabled()) {
    const auto c = color.getStrokeColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
  }
}
void Shape::beginShape(const Color& color) {
  glBegin(GL_LINE_LOOP);
  const auto c = color.getStrokeColor();
  glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
  glLineWidth(weight_);
}
void Shape::vertex(float x, float y) { glVertex2d(x, y); }
void Shape::endShape() { glEnd(); }
void Shape::rect(float x, float y, float w, float h, const Color& color) {
  glLineWidth(weight_);
  if (color.isFillEnabled()) {
    const auto c = color.getFillColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
    glEnd();
  }
  if (color.isStrokeEnabled()) {
    const auto c = color.getStrokeColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
    glEnd();
  }
}
void Shape::ellipse(float x, float y, float w, float h, const Color& color) {
  glLineWidth(weight_);
  if (color.isFillEnabled()) {
    const auto c = color.getFillColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    glBegin(GL_POLYGON);
    for (float i = 0.0f; i < TWO_PI; i += 0.01f) {
      const float px = x + ((w / 2.0f) * std::cos(i));
      const float py = y + ((h / 2.0f) * std::sin(i));
      glVertex2d(px, py);
    }
    glEnd();
  }
  if (color.isStrokeEnabled()) {
    glBegin(GL_LINE_LOOP);
    const auto c = color.getStrokeColor();
    glColor4f(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    for (float i = 0.0f; i < TWO_PI; i += 0.01f) {
      const float px = x + ((w / 2.0f) * std::cos(i));
      const float py = y + ((h / 2.0f) * std::sin(i));
      glVertex2d(px, py);
    }
    glEnd();
  }
}
}  // namespace core
}  // namespace cp

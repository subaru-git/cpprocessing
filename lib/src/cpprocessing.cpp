#include "cpprocessing.hpp"
#include "main.hpp"
#include "math.hpp"

namespace {
cp::core::Main m;
cp::core::Math math;
}
int cp::main() { return m.start(); }

void cp::size(int width, int height) { m.size(width, height); }

void cp::background(int gray) { m.background(gray, gray, gray, 255); }
void cp::background(int gray, int a) { m.background(gray, gray, gray, a); }
void cp::background(int r, int g, int b) { m.background(r, g, b, 255); }
void cp::background(int r, int g, int b, int a) { m.background(r, g, b, a); }

void cp::point(float x, float y) { m.point(x, y); }

void cp::strokeWeight(float weight) { m.strokeWeight(weight); }

void cp::stroke(int gray) { m.stroke(gray, gray, gray, 255); }
void cp::stroke(int gray, int a) { m.stroke(gray, gray, gray, a); }
void cp::stroke(int r, int g, int b) { m.stroke(r, g, b, 255); }
void cp::stroke(int r, int g, int b, int a) { m.stroke(r, g, b, a); }

void cp::noStroke() { m.noStroke(); }

void cp::line(float x1, float y1, float x2, float y2) {
  m.line(x1, y1, x2, y2);
}

void cp::beginShape() { m.beginShape(); }

void cp::vertex(float x, float y) { m.vertex(x, y); }

void cp::endShape() { m.endShape(); }

void cp::translate(float x, float y) { m.translate(x, y); }

void cp::pushMatrix() { m.pushMatrix(); }

void cp::popMatrix() { m.popMatrix(); }

void cp::rotate(float angle) { m.rotate(angle); }

void cp::rect(float x, float y, float w, float h) { m.rect(x, y, w, h); }

void cp::fill(int gray) { m.fill(gray, gray, gray, 255); }
void cp::fill(int gray, int a) { m.fill(gray, gray, gray, a); }
void cp::fill(int r, int g, int b) { m.fill(r, g, b, 255); }
void cp::fill(int r, int g, int b, int a) { m.fill(r, g, b, a); }

void cp::noFill() { m.noFill(); }

void cp::ellipse(float x, float y, float w, float h) { m.ellipse(x, y, w, h); }

float cp::noise(float x) { return math.noise(x); }
float cp::noise(float x, float y) { return math.noise(x, y); }
float cp::noise(float x, float y, float z) { return math.noise(x, y, z); }

float cp::map(float value, float start1, float stop1, float start2,
              float stop2) {
  return math.map(value, start1, stop1, start2, stop2);
}

float cp::random(float high) { return math.random(high); }
float cp::random(float low, float high) { return math.random(low, high); }

float cp::sin(float angle) { return cp::core::Math::sin(angle); }
float cp::cos(float angle) { return cp::core::Math::cos(angle); }
float cp::sqrt(float n) { return cp::core::Math::sqrt(n); }
float cp::atan(float value) { return cp::core::Math::atan(value); }
int cp::floor(float n) { return cp::core::Math::floor(n); }
int cp::ceil(float n) { return cp::core::Math::ceil(n); }

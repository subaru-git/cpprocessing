#pragma once
#include <GLFW/glfw3.h>
#include <src/constants.hpp>
#include <src/vector.hpp>

namespace cp {
int main();
void size(int width, int height);
void background(int gray);
void background(int gray, int a);
void background(int r, int g, int b);
void background(int r, int g, int b, int a);
void point(float x, float y);
void strokeWeight(float weight);
void stroke(int gray);
void stroke(int gray, int a);
void stroke(int r, int g, int b);
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
void fill(int gray);
void fill(int gray, int a);
void fill(int r, int g, int b);
void fill(int r, int g, int b, int a);
void noFill();
void ellipse(float x, float y, float w, float h);
float noise(float x);
float noise(float x, float y);
float noise(float x, float y, float z);
float map(float value, float start1, float stop1, float start2, float stop2);
float random(float high);
float random(float low, float high);
float sin(float angle);
float cos(float angle);
float sqrt(float n);
float atan(float value);
int floor(float n);
int ceil(float n);
}  // namespace cp

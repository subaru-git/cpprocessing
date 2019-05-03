#pragma once
#include <random>
#include "perlinnoise.hpp"

namespace cp {
namespace core {
class Math {
 public:
  Math();
  ~Math();

  float noise(float x);
  float noise(float x, float y);
  float noise(float x, float y, float z);
  static float map(float value, float start1, float stop1, float start2,
                   float stop2);
  static float lerp(float start, float stop, float amt);
  float random(float high);
  float random(float low, float high);
  static float sin(float angle);
  static float cos(float angle);
  static float sqrt(float n);
  static float atan(float value);
  static float atan2(float y, float x);
  static float acos(float value);
  static int floor(float n);
  static int ceil(float n);

 private:
  PerlinNoise perlinnoise_;
  std::mt19937 engine_;
};
}  // namespace core

}  // namespace cp

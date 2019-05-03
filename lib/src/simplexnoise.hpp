#pragma once

namespace cp {
namespace core {
class SimplexNoise {
 public:
  SimplexNoise();
  float noise(float x);
  float noise(float x, float y);
  float noise(float x, float y, float z);

 private:
};
}  // namespace core
}  // namespace cp

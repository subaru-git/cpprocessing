#pragma once
#include <random>
#include <vector>

namespace cp {
namespace core {
class PerlinNoise {
 public:
  PerlinNoise();
  ~PerlinNoise();

  float noise(float x, float y, float z);

  static void InitializePerlinNoise();
  static void TerminatePerlinNoise();

 private:
  std::vector<float> perlin_;
  std::mt19937 engine_;
  int perlin_octaves_ = 4;
  float perlin_amp_falloff_ = 0.5f;

  float noise_fsc(float i);
};
}  // namespace core
}  // namespace cp

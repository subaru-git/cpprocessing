#include "math.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include "perlinnoise.hpp"
#include "simplexnoise.hpp"

namespace cp {
namespace core {
Math::Math() {
  std::array<std::seed_seq::result_type, std::mt19937::state_size> seed_data;
  std::random_device gen;
  std::generate(seed_data.begin(), seed_data.end(), std::ref(gen));
  std::seed_seq seq(seed_data.begin(), seed_data.end());
  engine_.seed(seq);
}
Math::~Math() {}
float Math::noise(float x) { return perlinnoise_.noise(x, 0.0f, 0.0f); }
float Math::noise(float x, float y) { return perlinnoise_.noise(x, y, 0.0f); }
float Math::noise(float x, float y, float z) {
  return perlinnoise_.noise(x, y, z);
}
float Math::map(float value, float start1, float stop1, float start2,
                float stop2) {
  const float outgoing =
      start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
  std::string badness = "";
  if (outgoing != outgoing) {
    badness = "NaN (not a number)";
  } else if (outgoing == std::numeric_limits<float>::infinity() ||
             outgoing == -std::numeric_limits<float>::infinity()) {
    badness = "infinity";
  }

  if (badness != "") {
    std::cout << "map(" << value << ", " << start1 << ", " << stop1 << ", "
              << start2 << ", " << stop2 << ") called, which returns "
              << badness << std::endl;
  }
  return outgoing;
}
float Math::lerp(float start, float stop, float amt) {
  return start + (stop - start) * amt;
}
float Math::random(float high) {
  std::uniform_real_distribution<> d(0.0f, 1.0f);
  return d(engine_) * high;
}
float Math::random(float low, float high) {
  const float diff = high - low;
  return random(diff) + low;
}
float Math::sin(float angle) { return std::sin(angle); }
float Math::cos(float angle) { return std::cos(angle); }
float Math::sqrt(float n) { return std::sqrt(n); }
float Math::atan(float value) { return std::atan(value); }
float Math::atan2(float x, float y) { return std::atan2(y, x); }
float Math::acos(float value) { return std::acos(value); }
int Math::floor(float n) { return std::floor(n); }
int Math::ceil(float n) { return std::ceil(n); }
}  // namespace core
}  // namespace cp

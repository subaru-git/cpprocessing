#include "perlinnoise.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include "constants.hpp"

namespace {
constexpr int PERLIN_YWRAPB = 4;
constexpr int PERLIN_YWRAP = 1 << PERLIN_YWRAPB;
constexpr int PERLIN_ZWRAPB = 8;
constexpr int PERLIN_ZWRAP = 1 << PERLIN_ZWRAPB;
constexpr int PERLIN_SIZE = 4095;
constexpr float SINCOS_PRECISION = 0.5f;
constexpr int SINCON_LENGTH = static_cast<int>(360.0f / SINCOS_PRECISION);
constexpr float DEG_TO_RAD = cp::PI / 180.0f;
constexpr int perlin_TWOPI = SINCON_LENGTH;
constexpr int perlin_PI = SINCON_LENGTH >> 1;
std::vector<float> perlin_cosTable;
}

namespace cp {
namespace core {
void PerlinNoise::InitializePerlinNoise() {
  for (int i = 0; i < SINCON_LENGTH; i++) {
    perlin_cosTable.push_back(
        static_cast<float>(std::cos(i * DEG_TO_RAD * SINCOS_PRECISION)));
  }
}
void PerlinNoise::TerminatePerlinNoise() {}
PerlinNoise::PerlinNoise() {}
PerlinNoise::~PerlinNoise() {}
float PerlinNoise::noise(float x, float y, float z) {
  if (perlin_.empty()) {
    std::array<std::seed_seq::result_type, std::mt19937::state_size> seed_data;
    std::random_device gen;
    std::generate(seed_data.begin(), seed_data.end(), std::ref(gen));
    std::seed_seq seq(seed_data.begin(), seed_data.end());
    engine_.seed(seq);
    std::uniform_real_distribution<> d(0.0f, 1.0f);
    for (int i = 0; i < PERLIN_SIZE + 1; i++) {
      perlin_.push_back(d(engine_));
    }
  }
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  if (z < 0) z = -z;

  int xi = static_cast<int>(x);
  int yi = static_cast<int>(y);
  int zi = static_cast<int>(z);
  float xf = x - xi;
  float yf = y - yi;
  float zf = z - zi;
  float rxf, ryf;

  float r = 0;
  float ampl = 0.5f;

  float n1, n2, n3;
  for (int i = 0; i < perlin_octaves_; i++) {
    int of = xi + (yi << PERLIN_YWRAPB) + (zi << PERLIN_ZWRAPB);
    rxf = noise_fsc(xf);
    ryf = noise_fsc(yf);
    n1 = perlin_[of & PERLIN_SIZE];
    n1 += rxf * (perlin_[(of + 1) & PERLIN_SIZE] - n1);
    n2 = perlin_[(of + PERLIN_YWRAP) & PERLIN_SIZE];
    n2 += rxf * (perlin_[(of + PERLIN_YWRAP + 1) & PERLIN_SIZE] - n2);
    n1 += ryf * (n2 - n1);

    of += PERLIN_ZWRAP;
    n2 = perlin_[of & PERLIN_SIZE];
    n2 += rxf * (perlin_[(of + 1) & PERLIN_SIZE] - n2);
    n3 = perlin_[(of + PERLIN_YWRAP) & PERLIN_SIZE];
    n3 += rxf * (perlin_[(of + PERLIN_YWRAP + 1) & PERLIN_SIZE] - n3);
    n2 += ryf * (n3 - n2);

    n1 += noise_fsc(zf) * (n2 - n1);

    r += n1 * ampl;
    ampl *= perlin_amp_falloff_;
    xi <<= 1;
    xf *= 2;
    yi <<= 1;
    yf *= 2;
    zi <<= 1;
    zf *= 2;

    if (xf >= 1.0f) {
      xi++;
      xf--;
    }
    if (yf >= 1.0f) {
      yi++;
      yf--;
    }
    if (zf >= 1.0f) {
      zi++;
      zf--;
    }
  }
  return r;
}
float PerlinNoise::noise_fsc(float i) {
  return 0.5f *
         (1.0f -
          perlin_cosTable[static_cast<int>(i * perlin_PI) % perlin_TWOPI]);
}
}  // namespace core
}  // namespace cp

#pragma once

namespace cp {
namespace data {
class Color {
 public:
  int r;
  int g;
  int b;
  int a;
};
}  // namespace data
namespace core {

class Color {
 public:
  Color();
  ~Color();

  void background(int r, int g, int b, int a);
  void stroke(int r, int g, int b, int a);
  void noStroke();
  void fill(int r, int g, int b, int a);
  void noFill();

  const data::Color& getStrokeColor() const;
  const data::Color& getFillColor() const;
  bool isFillEnabled() const;
  bool isStrokeEnabled() const;

 private:
  data::Color stroke_{0, 0, 0, 255};
  data::Color fill_{255, 255, 255, 255};
  bool fillenabled_ = true;
  bool strokeenabled_ = true;
};

}  // namespace core
}  // namespace cp

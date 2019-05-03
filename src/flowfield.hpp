#pragma once

#include <vector>
#include "cpprocessing.hpp"

class FlowField {
 public:
  explicit FlowField(int res);
  void update();
  void display();
  int getScale() const;
  int getCols() const;
  const cp::data::Vector& getVector(int index);

 private:
  std::vector<cp::data::Vector> vectors_;
  int cols_;
  int rows_;
  float inc_ = 0.1f;
  float zoff_ = 0.0f;
  int scl_;
};

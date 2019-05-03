#include "flowfield.hpp"

FlowField::FlowField(int res)
    : scl_(res),
      cols_(cp::floor(cp::width / res) + 1),
      rows_(cp::floor(cp::height / res) + 1) {
  vectors_.resize(cols_ * rows_);
}

void FlowField::update() {
  float xoff = 0.0f;
  for (int y = 0; y < rows_; y++) {
    float yoff = 0.0f;
    for (int x = 0; x < cols_; x++) {
      const float angle = cp::noise(xoff, yoff, zoff_) * cp::TWO_PI * 4;
      cp::data::Vector v = cp::data::Vector::fromAngle(angle);
      v.setMag(1);
      const int index = x + y * cols_;
      vectors_[index] = v;
      xoff += inc_;
    }
    yoff += inc_;
  }
  zoff_ += 0.004;
}

void FlowField::display() {
  for (int y = 0; y < rows_; y++) {
    for (int x = 0; x < cols_; x++) {
      const int index = x + y * cols_;
      cp::data::Vector v = vectors_[index];
      cp::stroke(0, 40);
      cp::strokeWeight(0.1f);
      cp::pushMatrix();
      cp::rotate(v.heading());
      cp::line(0.0f, 0.0f, scl_, 0.0f);
      cp::popMatrix();
    }
  }
}

int FlowField::getScale() const { return scl_; }

int FlowField::getCols() const { return cols_; }

const cp::data::Vector& FlowField::getVector(int index) {
  return vectors_[index];
}
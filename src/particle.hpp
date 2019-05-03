#pragma once

#include "cpprocessing.hpp"
#include "flowfield.hpp"

class Particle {
 public:
  Particle(const cp::data::Vector& start, float maxspeed);
  void run();
  void update();
  void applyForce(const cp::data::Vector& force);
  void show();
  void edges();
  void updatePreviousPos();
  void follow(FlowField flowField);

 private:
  cp::data::Vector pos_;
  cp::data::Vector vel_;
  cp::data::Vector acc_;
  cp::data::Vector previousPos_;
  float maxSpeed_;
};

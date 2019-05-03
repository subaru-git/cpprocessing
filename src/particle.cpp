#include "particle.hpp"

Particle::Particle(const cp::data::Vector& start, float maxspeed)
    : maxSpeed_(maxspeed), pos_(start), previousPos_(start) {}

void Particle::run() {
  update();
  edges();
  show();
}

void Particle::update() {
  pos_.add(vel_);
  vel_.limit(maxSpeed_);
  vel_.add(acc_);
  acc_.mult(0.0f);
}

void Particle::applyForce(const cp::data::Vector& force) { acc_.add(force); }

void Particle::show() {
  cp::stroke(0, 5);
  cp::strokeWeight(1.0f);
  cp::line(pos_.x, pos_.y, previousPos_.x, previousPos_.y);
  updatePreviousPos();
}

void Particle::edges() {
  if (pos_.x > cp::width) {
    pos_.x = 0;
    updatePreviousPos();
  }
  if (pos_.x < 0) {
    pos_.x = cp::width;
    updatePreviousPos();
  }
  if (pos_.y > cp::height) {
    pos_.y = 0;
    updatePreviousPos();
  }
  if (pos_.y < 0) {
    pos_.y = cp::height;
    updatePreviousPos();
  }
}

void Particle::updatePreviousPos() {
  previousPos_.x = pos_.x;
  previousPos_.y = pos_.y;
}

void Particle::follow(FlowField flowfield) {
  const int x = cp::floor(pos_.x / flowfield.getScale());
  const int y = cp::floor(pos_.y / flowfield.getScale());
  const int index = x + y * flowfield.getCols();
  const cp::data::Vector force = flowfield.getVector(index);
  applyForce(force);
}

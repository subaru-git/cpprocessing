#include <cpprocessing.hpp>
#include <iostream>
#include <vector>
#include "flowfield.hpp"
#include "particle.hpp"

using cp::data::Vector;

namespace {
FlowField* flowfield;
std::vector<Particle*> particles;
}

void setup() {
  cp::size(600, 400);
  flowfield = new FlowField(10);
  flowfield->update();

  for (int i = 0; i < 10000; i++) {
    const Vector* start =
        new Vector(cp::random(cp::width), cp::random(cp::height));
    particles.push_back(new Particle(*start, cp::random(2.0f, 8.0f)));
  }
  cp::background(255);
}

void draw() {
  flowfield->update();
  for (auto p : particles) {
    p->follow(*flowfield);
    p->run();
  }
}

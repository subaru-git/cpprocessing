#include "vector.hpp"
#include "constants.hpp"
#include "math.hpp"

namespace cp {
namespace data {
Vector::Vector() : Vector(0.0f, 0.0f, 0.0f) {}
Vector::Vector(float x, float y) : Vector(x, y, 0.0f) {}
Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}
Vector::Vector(const Vector& rhs) {
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
}
Vector& Vector::set(float x, float y) { return set(x, y, 0.0f); }
Vector& Vector::set(Vector v) { return set(v.x, v.y, v.z); }
Vector& Vector::set(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
  return *this;
}
Vector& Vector::fromAngle(float angle) { return fromAngle(angle, nullptr); }
Vector& Vector::fromAngle(float angle, Vector* target) {
  if (target == nullptr) {
    target = new Vector(core::Math::cos(angle), core::Math::sin(angle), 0.0f);
  } else {
    target->set(core::Math::cos(angle), core::Math::sin(angle), 0.0f);
  }
  return *target;
}
Vector& Vector::random2D(Vector* target) {
  return fromAngle(core::Math{}.random(TWO_PI), target);
}
Vector& Vector::random2D() {
  return fromAngle(core::Math{}.random(TWO_PI), nullptr);
}
Vector& Vector::copy() const { return *(new Vector(x, y, z)); }
float Vector::mag() { return core::Math::sqrt(x * x + y * y + z * z); }
float Vector::magSq() { return (x * x + y * y + z * z); }
Vector& Vector::add(const Vector& v) { return add(v.x, v.y, v.z); }
Vector& Vector::add(float x, float y) { return add(x, y, z); }
Vector& Vector::add(float x, float y, float z) {
  this->x += x;
  this->y += y;
  this->z += z;
  return *this;
}
Vector& Vector::add(const Vector& v1, const Vector& v2) {
  return add(v1, v2, nullptr);
}
Vector& Vector::add(const Vector& v1, const Vector& v2, Vector* target) {
  if (target == nullptr) {
    target = new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
  } else {
    target->set(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
  }
  return *target;
}
Vector& Vector::sub(const Vector& v) { return sub(v.x, v.y, v.z); }
Vector& Vector::sub(float x, float y) { return sub(x, y, z); }
Vector& Vector::sub(float x, float y, float z) {
  this->x -= x;
  this->y -= y;
  this->z -= z;
  return *this;
}
Vector& Vector::sub(const Vector& v1, const Vector& v2) {
  return sub(v1, v2, nullptr);
}
Vector& Vector::sub(const Vector& v1, const Vector& v2, Vector* target) {
  if (target == nullptr) {
    target = new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
  } else {
    target->set(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
  }
  return *target;
}
Vector& Vector::mult(float n) {
  x *= n;
  y *= n;
  z *= n;
  return *this;
}
Vector& Vector::mult(const Vector& v, float n) { return mult(v, n, nullptr); }
Vector& Vector::mult(const Vector& v, float n, Vector* target) {
  if (target == nullptr) {
    target = new Vector(v.x * n, v.y * n, v.z * n);
  } else {
    target->set(v.x * n, v.y * n, v.z * n);
  }
  return *target;
}
Vector& Vector::div(float n) {
  x /= n;
  y /= n;
  z /= n;
  return *this;
}
Vector& Vector::div(const Vector& v, float n) { return div(v, n, nullptr); }
Vector& Vector::div(const Vector& v, float n, Vector* target) {
  if (target == nullptr) {
    target = new Vector(v.x / n, v.y / n, v.z / n);
  } else {
    target->set(v.x / n, v.y / n, v.z / n);
  }
  return *target;
}
float Vector::dist(const Vector& v) {
  const float dx = x - v.x;
  const float dy = y - v.y;
  const float dz = z - v.z;
  return core::Math::sqrt(dx * dx + dy * dy + dz * dz);
}
float Vector::dist(const Vector& v1, const Vector& v2) {
  const float dx = v1.x - v2.x;
  const float dy = v1.y - v2.y;
  const float dz = v1.z - v2.z;
  return core::Math::sqrt(dx * dx + dy * dy + dz * dz);
}
float Vector::dot(const Vector& v) { return x * v.x + y * v.y + z * v.z; }
float Vector::dot(float x, float y, float z) {
  return this->x * x + this->y * y + this->z * z;
}
float Vector::dot(const Vector& v1, const Vector& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
Vector& Vector::cross(const Vector& v) { return cross(v, nullptr); }
Vector& Vector::cross(const Vector& v, Vector* target) {
  const float cx = y * v.z - v.y * z;
  const float cy = z * v.x - v.z * x;
  const float cz = x * v.y - v.x * y;
  if (target == nullptr) {
    target = new Vector(cx, cy, cz);
  } else {
    target->set(cx, cy, cz);
  }
  return *target;
}
Vector& Vector::cross(const Vector& v1, const Vector& v2, Vector* target) {
  const float cx = v1.y * v2.z - v2.y * v1.z;
  const float cy = v1.z * v2.x - v2.z * v1.x;
  const float cz = v1.x * v2.y - v2.x * v1.y;
  if (target == nullptr) {
    target = new Vector(cx, cy, cz);
  } else {
    target->set(cx, cy, cz);
  }
  return *target;
}
Vector& Vector::normalize() {
  const float m = mag();
  if (m != 0 && m != 1) div(m);
  return *this;
}
Vector& Vector::normalize(Vector* target) {
  if (target == nullptr) {
    target = new Vector();
  }
  const float m = mag();
  if (m > 0) {
    target->set(x / m, y / m, z / m);
  } else {
    target->set(x, y, z);
  }
  return *target;
}
Vector& Vector::limit(float max) {
  if (magSq() > max * max) {
    normalize();
    mult(max);
  }
  return *this;
}
Vector& Vector::setMag(float len) {
  normalize();
  mult(len);
  return *this;
}
Vector& Vector::setMag(float len, Vector* target) {
  *target = normalize(target);
  target->mult(len);
  return *target;
}
float Vector::heading() { return core::Math::atan2(y, x); }
Vector& Vector::rotate(float theta) {
  core::Math m{};
  const float nx = x * m.cos(theta) - y * m.sin(theta);
  const float ny = x * m.sin(theta) + y * m.cos(theta);
  x = nx;
  y = ny;
  return *this;
}
Vector& Vector::lerp(const Vector& v, float amt) {
  core::Math m{};
  x = m.lerp(x, v.x, amt);
  y = m.lerp(y, v.y, amt);
  z = m.lerp(z, v.z, amt);
  return *this;
}
Vector& Vector::lerp(float x, float y, float z, float amt) {
  core::Math m{};
  this->x = m.lerp(this->x, x, amt);
  this->y = m.lerp(this->y, y, amt);
  this->z = m.lerp(this->z, z, amt);
  return *this;
}
Vector& Vector::lerp(const Vector& v1, const Vector& v2, float amt) {
  core::Math m{};
  Vector& v = v1.copy();
  v.lerp(v2, amt);
  return v;
}
float Vector::angleBetween(const Vector& v1, const Vector& v2) {
  if (v1.x == 0 && v1.y == 0 && v1.z == 0) return 0.0f;
  if (v2.x == 0 && v2.y == 0 && v2.z == 0) return 0.0f;
  const float dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  const float v1mag = core::Math::sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
  const float v2mag = core::Math::sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
  const float amt = dot / (v1mag * v2mag);
  if (amt <= -1) {
    return PI;
  } else if (amt >= 1) {
    return 0;
  }
  return core::Math::acos(amt);
}
bool Vector::operator==(const Vector& v) {
  return (x == v.x && y == v.y && z == v.z);
}
Vector& Vector::operator=(const Vector& v) {
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
}
}  // namespace data
}  // namespace cp

#pragma once

namespace cp {
namespace data {
class Vector {
 public:
  Vector();
  Vector(float x, float y);
  Vector(float x, float y, float z);
  Vector(const Vector& rhs);
  Vector& set(float x, float y);
  Vector& set(Vector v);
  Vector& set(float x, float y, float z);
  static Vector& fromAngle(float angle);
  static Vector& fromAngle(float angle, Vector* target);
  static Vector& random2D();
  static Vector& random2D(Vector* target);
  Vector& copy() const;
  float mag();
  float magSq();
  Vector& add(const Vector& v);
  Vector& add(float x, float y);
  Vector& add(float x, float y, float z);
  Vector& add(const Vector& v1, const Vector& v2);
  Vector& add(const Vector& v1, const Vector& v2, Vector* target);
  Vector& sub(const Vector& v);
  Vector& sub(float x, float y);
  Vector& sub(float x, float y, float z);
  Vector& sub(const Vector& v1, const Vector& v2);
  Vector& sub(const Vector& v1, const Vector& v2, Vector* target);
  Vector& mult(float n);
  Vector& mult(const Vector& v, float n);
  Vector& mult(const Vector& v, float n, Vector* target);
  Vector& div(float n);
  Vector& div(const Vector& v, float n);
  Vector& div(const Vector& v, float n, Vector* target);
  float dist(const Vector& v);
  static float dist(const Vector& v1, const Vector& v2);
  float dot(const Vector& v);
  float dot(float x, float y, float z);
  static float dot(const Vector& v1, const Vector& v2);
  Vector& cross(const Vector& v);
  Vector& cross(const Vector& v, Vector* target);
  static Vector& cross(const Vector& v1, const Vector& v2, Vector* target);
  Vector& normalize();
  Vector& normalize(Vector* target);
  Vector& limit(float max);
  Vector& setMag(float len);
  Vector& setMag(float len, Vector* target);
  float heading();
  Vector& rotate(float theta);
  Vector& lerp(const Vector& v, float amt);
  Vector& lerp(float x, float y, float z, float amt);
  static Vector& lerp(const Vector& v1, const Vector& v2, float amt);
  static float angleBetween(const Vector& v1, const Vector& v2);

  bool operator==(const Vector& v);
  Vector& operator=(const Vector& v);

  float x;
  float y;
  float z;

 private:
  // float array[];
};
}  // namespace data
}  // namespace cp

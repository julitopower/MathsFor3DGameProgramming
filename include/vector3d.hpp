#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <vector>

namespace m3d {
  class Vector3f {
  public:
    Vector3f(float x, float y, float z);
    Vector3f(const float* const data);
    Vector3f(const std::vector<float>& data);
    Vector3f(const Vector3f& other);

    void operator+=(const Vector3f& rhs);
    Vector3f operator+(const Vector3f& rhs) const;

    void operator*=(float rhs);
    Vector3f operator*(float rhs) const;

    void operator/=(float rhs);
    Vector3f operator/(float rhs) const;

    void operator-=(const Vector3f& rhs);
    Vector3f operator-(const Vector3f& rhs) const;

    float dot(const Vector3f& rhs) const;
    Vector3f cross(const Vector3f& rhs) const;

    const float* data() const;

    const float& operator[](int idx) const;
    float& operator[](int idx);

  private:
    float _data[3];
  };

  inline std::ostream& operator<<(std::ostream& os, const Vector3f vec) {
    os << "x: " << vec[0] << ", y: " << vec[1] << ", z: " << vec[2] << std::endl;
  }
}

#endif /* VECTOR3D_H */

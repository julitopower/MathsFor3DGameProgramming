#include <cstring>
#include <functional>
#include <iostream>
#include <type_traits>

#include <vector.hpp>

namespace {

  /* 
   * These two functions allow us to easily declare
   * operators scalar op vector
   */
  template<class LHS, class RHS, class OP>
  void inplace_op(LHS* lhs, const RHS& rhs, OP op) {
    auto lhs_ptr = lhs;
    auto rhs_ptr = rhs;;
    for(auto i = 0U ; i < 3; ++i) {
      op(*(lhs_ptr++), *(rhs_ptr++));
    }    
  }

  template<class T, class OP>
  T op(T& lhs, T& rhs, OP o) {
    auto result = lhs;
    o(result, rhs);
    return result;    
  }
}

namespace m3d {
  Vector3f::Vector3f(float x, float y, float z) {
    auto ptr = _data;
    *(ptr++) = x;
    *(ptr++) = y;    
    *(ptr++) = z;
  }

  Vector3f::Vector3f(const float* const data) {
    std::memcpy(_data, data, 3 * sizeof(float));
  }

  Vector3f::Vector3f(const std::vector<float>& data) {
    std::memcpy(_data, data.data(), 3 * sizeof(float));
  }

  Vector3f::Vector3f(const Vector3f& other) {
    std::memcpy(_data, other.data(), 3 * sizeof(float));    
  }

  void Vector3f::operator+=(const Vector3f& rhs) {
    inplace_op(this->_data, rhs.data(), [](float& l, const float& r) {l += r;});
  }

  Vector3f Vector3f::operator+(const Vector3f& rhs) const {    
    return op(*this, rhs, [](Vector3f& l, const Vector3f& r) {l += r;});
  }

  void Vector3f::operator-=(const Vector3f& rhs) {
    inplace_op(this->_data, rhs.data(), [](float& l, const float& r) {l -= r;});
  }

  Vector3f Vector3f::operator-(const Vector3f& rhs) const {
    return op(*this, rhs, [](Vector3f& l, const Vector3f& r) {l -= r;});
  }

  void Vector3f::operator*=(float rhs) {
    for (auto i = 0U ; i < 3 ; ++i) {
      (*this)[i] *= rhs;
    }
  }

  Vector3f Vector3f::operator*(float rhs) const {
    Vector3f result = *this;
    result *= rhs;
    return result;
  }

  void Vector3f::operator/=(float rhs) {
    for (auto i = 0U ; i < 3 ; ++i) {
      (*this)[i] /= rhs;
    }
  }

  Vector3f Vector3f::operator/(float rhs) const {
    Vector3f result = *this;
    result /= rhs;
    return result;
  }

  float Vector3f::dot(const Vector3f& rhs) const {
    float result = 0.0f;

    auto lhs_ptr = _data;
    auto rhs_ptr = rhs.data();
    for(auto i = 0U ; i < 3; ++i) {
      result += *(lhs_ptr++) * *(rhs_ptr++);
    }

    return result;
  }

  Vector3f Vector3f::cross(const Vector3f& rhs) const {
    const auto l = _data;
    const auto r = rhs.data();
    
    return Vector3f {
          l[1]*r[2] - l[2]*r[1], 
	    -(l[0]*r[2] - l[2]*r[0]),
	  l[0]*r[1] - l[1]*r[0]
	  };
  }

  const float& Vector3f::operator[](int idx) const {
    return _data[idx];
  }

  float& Vector3f::operator[](int idx) {
    return _data[idx];
  }

  const float* Vector3f::data() const {
    return _data;
  }

}

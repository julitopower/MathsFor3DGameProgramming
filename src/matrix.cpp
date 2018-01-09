#include <cstring>

#include <matrix.hpp>

namespace m3d {
  Matrix3x3f::Matrix3x3f(const float* const data) {
    std::memcpy(_data, data, 9 * sizeof(float));
  }

  Matrix3x3f::Matrix3x3f(const std::vector<float>& data) {
    std::memcpy(_data, data.data(), 9 * sizeof(float));

  }

  Matrix3x3f::Matrix3x3f(const Matrix3x3f& other) {
    std::memcpy(_data, other.data(), 9 * sizeof(float));
  }
  
  const float* Matrix3x3f::data() const {
    return _data;
  }
  
  const float& Matrix3x3f::at(int row, int col) const {
    return _data[row * 3 + col];
  }
  
  float& Matrix3x3f::at(int row, int col) {
    return _data[row * 3 + col];    
  }
}

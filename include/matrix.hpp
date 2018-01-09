#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

namespace m3d {

  class Matrix3x3f {
  public:
    Matrix3x3f(const float* const data);
    Matrix3x3f(const std::vector<float>& data);
    Matrix3x3f(const Matrix3x3f& other);
    const float* data() const;
    const float& at(int row, int col) const;
    float& at(int row, int col);
  private:
    float _data[9];
  };

  inline std::ostream& operator<<(std::ostream& os, const Matrix3x3f& mat) {
    os << "[";
    for (auto i = 0U ; i < 3 ; ++i) {
      os << "[";
      for (auto j = 0U ; j < 3 ; ++j) {
	os << mat.data()[i * 3 + j] << (j != 2) ? ", " : "";
      }
      os << "]" << std::endl;
    }
    os << "]" << std::endl;
  }
}

#endif /* MATRIX_H */

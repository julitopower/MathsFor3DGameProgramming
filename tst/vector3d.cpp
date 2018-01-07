#include <vector3d.hpp>
#include <iostream>

#define ASSERT(lhs, rhs, msg)						\
  if (lhs != rhs) {							\
    std::cerr << msg << " " << lhs << " != " << rhs << std::endl;	\
    exit(-1);								\
  }

int main(int argc, char** argv)
{
  using namespace m3d;
  Vector3f v1 {0.0, 0.0, 0.0};
  Vector3f v2 {1.0, 2.0, 3.0};

  {
    Vector3f v3 = v1 + v2;
    for (auto i = 0U ; i < 3; ++i) {
      ASSERT(v3[i], static_cast<float>(i + 1), "Bad Add.");
    }  
  }

  {
    Vector3f v3 = v1 - v2;
    for (auto i = 0 ; i < 3; ++i) {
      ASSERT(v3[i], static_cast<float>(-i - 1), "Bad subtract.");
    }  
  }

  {
    Vector3f v3 = v2 * 2;
    for (auto i = 0 ; i < 3; ++i) {
      ASSERT(v3[i], v2[i] * 2, "Bad scalar product.");
    }  
  }

  {
    Vector3f v3 = v2 / 2;
    for (auto i = 0 ; i < 3; ++i) {
      ASSERT(v3[i], v2[i] / 2, "Bad scalar division.");
    }  
  }

  {
    Vector3f v3 {2.0, 2.0, 2.0};
    ASSERT(v3.dot(v2), 12, "Bad dot product");
    ASSERT(v2.dot(v3), 12, "Bad dot product");
  }

  {
    Vector3f v3 {2.0, 2.0, 2.0};
    auto cross_vector = v2.cross(v3);
    ASSERT(v3.dot(cross_vector), 0, "Should be perpendicular");
    ASSERT(v2.dot(cross_vector), 0, "Should be perpendicular");
  }

  return 0;
}

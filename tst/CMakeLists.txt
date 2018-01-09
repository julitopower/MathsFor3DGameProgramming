add_executable(vector3f vector_test.cpp)
target_link_libraries(vector3f vector3d)

add_test(vector3f_test vector3f)

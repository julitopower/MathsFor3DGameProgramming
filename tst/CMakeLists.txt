add_executable(vector3f vector3d.cpp)
target_link_libraries(vector3f vector3d)

add_test(vector3f vector3f)

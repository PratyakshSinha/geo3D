cmake_minimum_required(VERSION 3.20)
project(Geo3D)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

add_executable(Geo3D 
    src/main.cpp
    src/core/Vec3.cpp
    src/core/Mat4.cpp
    src/core/Ray.cpp
    src/core/Plane.cpp
)

add_executable(Geo3DTests
    tests/Vec3Tests.cpp
    tests/Mat4Tests.cpp
    tests/RayTests.cpp
    tests/PlaneTests.cpp
    src/core/Vec3.cpp
    src/core/Mat4.cpp
    src/core/Ray.cpp
    src/core/Plane.cpp
)

target_link_libraries(Geo3DTests gtest gtest_main)
target_include_directories(Geo3DTests PRIVATE src)

enable_testing()
add_test(NAME Geo3DTests COMMAND Geo3DTests)
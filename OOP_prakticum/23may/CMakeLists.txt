cmake_minimum_required(VERSION 3.0.0)
project(shapes VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(shapes main.cpp Triangle.cpp Circle.cpp Point.cpp Rectangle.cpp Shape.cpp ShapeCollector.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

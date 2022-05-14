cmake_minimum_required(VERSION 3.0.0)
project(furniture VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(furniture main.cpp Furniture.cpp Table.cpp Bed.cpp Chair.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

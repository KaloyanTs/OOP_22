cmake_minimum_required(VERSION 3.0.0)
project(car VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(car main.cpp CarPart.cpp Engine.cpp Tyre.cpp Battery.cpp FuelTank.cpp Car.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

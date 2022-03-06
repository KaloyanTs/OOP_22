cmake_minimum_required(VERSION 3.0.0)
project(fun VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(fun main.cpp NightClub.cpp Balloon.cpp Shisha.cpp Alcohol.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

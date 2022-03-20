cmake_minimum_required(VERSION 3.0.0)
project(uni VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(uni main.cpp Student.cpp Specialty.cpp Subject.cpp University.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

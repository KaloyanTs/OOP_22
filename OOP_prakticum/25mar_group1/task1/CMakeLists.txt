cmake_minimum_required(VERSION 3.0.0)
project(corporation VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(corporation main.cpp Employee.cpp EmployeeVector.cpp Corporation.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

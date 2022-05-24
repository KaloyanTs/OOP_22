cmake_minimum_required(VERSION 3.0.0)
project(zimbu VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(zimbu main.cpp Component.cpp CPU.cpp Memory.cpp Configuration.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

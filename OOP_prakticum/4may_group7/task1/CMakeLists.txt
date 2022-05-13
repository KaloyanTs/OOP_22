cmake_minimum_required(VERSION 3.0.0)
project(fauna VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(fauna main.cpp Pet.cpp Animal.cpp WildAnimal.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

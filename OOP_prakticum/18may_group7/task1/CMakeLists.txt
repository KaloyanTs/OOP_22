cmake_minimum_required(VERSION 3.0.0)
project(office VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(office main.cpp ChillRoom.cpp ConferenceRoom.cpp OfficeBuilding.cpp Room.cpp Office.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.0.0)
project(battle_ships VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(battle_ships main.cpp Map.cpp Ship.cpp Player.cpp Game.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

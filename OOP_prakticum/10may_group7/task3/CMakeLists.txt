cmake_minimum_required(VERSION 3.0.0)
project(rpg VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(rpg main.cpp Weapon.cpp Enemy.cpp Hero.cpp Barbarian.cpp Assassin.cpp Sorcerer.cpp Warrior.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

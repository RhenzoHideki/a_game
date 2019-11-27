cmake_minimum_required(VERSION 3.15)
project(Game C)

set(CMAKE_C_STANDARD 99)

add_executable(Game main.c character.h fight.h)
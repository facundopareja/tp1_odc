cmake_minimum_required(VERSION 3.29)
project(TP0_OrgaComputadoras C)

set(CMAKE_C_STANDARD 11)
add_executable(autcel main.c)
target_link_libraries(autcel  m)

cmake_minimum_required(VERSION 3.29)
project(TP0_OrgaComputadoras C)

set(CMAKE_C_STANDARD 11)
add_executable(autcel main.c
        pbm_writer.c
        pbm_writer.h
        constants.c
        constants.h
        input_parser.c
        input_parser.h)

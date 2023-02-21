cmake_minimum_required(VERSION 3.24)
project(new_proj C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(new_proj
        arbre.c
        arbre.h
        dico.c
        dico.h
        arbreTerminalPrint.c
        arbreTerminalPrint.h
        main.c arbreAfficherVertical.h arbreAfficherVertical.c)

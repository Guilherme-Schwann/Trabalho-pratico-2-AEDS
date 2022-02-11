cmake_minimum_required(VERSION 3.21)
project(TP2 C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES codigo/TAD-cidade/cidade.c codigo/TAD-cidade/cidade.h
        codigo/TAD-permuta/permuta.c codigo/TAD-permuta/permuta.h
        codigo/TAD-listaCidades/listaDeCidades.h codigo/TAD-listaCidades/listaDeCidades.c
        codigo/main/main.c codigo/main/demandas.c codigo/main/demandas.h codigo/main/distancias.c
        codigo/main/distancias.h)
add_executable(main ${SOURCE_FILES})

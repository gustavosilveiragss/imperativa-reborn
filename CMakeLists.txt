cmake_minimum_required(VERSION 3.20)

project(reborn LANGUAGES C)

include(cmake/compile_options.cmake)

# editor
add_executable(editor)
target_sources(editor PRIVATE src/editor/main.c)
target_compile_options(editor PRIVATE ${COMPILE_OPTIONS})
target_include_directories(editor PRIVATE include/)

# exporter
add_executable(exporter)
target_sources(exporter PRIVATE src/exporter/main.c)
target_compile_options(exporter PRIVATE ${COMPILE_OPTIONS})
target_include_directories(exporter PRIVATE include/)

# generator
add_executable(generator)
target_sources(generator PRIVATE src/generator/main.c)
target_compile_options(generator PRIVATE ${COMPILE_OPTIONS})
target_include_directories(generator PRIVATE include/)

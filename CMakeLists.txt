cmake_minimum_required(VERSION 3.20)

project(reborn LANGUAGES C)

include(shared/compile_options.cmake)
include(shared/pch.cmake)

# editor
add_executable(editor)
target_sources(editor PRIVATE src/editor/main.c)
target_compile_options(editor PRIVATE ${COMPILE_OPTIONS})
target_precompile_headers(editor PRIVATE ${PCH})

# exporter
add_executable(exporter)
target_sources(exporter PRIVATE src/exporter/main.c)
target_compile_options(exporter PRIVATE ${COMPILE_OPTIONS})
target_precompile_headers(exporter PRIVATE ${PCH})

# generator
add_executable(generator)
target_sources(generator PRIVATE src/generator/main.c)
target_compile_options(generator PRIVATE ${COMPILE_OPTIONS})
target_precompile_headers(generator PRIVATE ${PCH})

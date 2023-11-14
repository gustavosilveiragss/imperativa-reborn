cmake_minimum_required(VERSION 3.20)

project(reborn LANGUAGES C)

include(cmake/compile_options.cmake)

function(add_target name)
    add_executable(${name})
    target_sources(${name} PRIVATE
        src/${name}/main.c
        ${ARGN}
    )
    target_compile_options(${name} PRIVATE ${COMPILE_OPTIONS})
    target_include_directories(${name} PRIVATE include/)
endfunction()

# editor
add_target(editor)
add_target(exporter)
add_target(generator)

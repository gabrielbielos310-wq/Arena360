cmake_minimum_required(VERSION 3.25)
project(arena360 C)

add_executable(arena360
    src/main.c
    src/game/game_state.c
)

set_target_properties(arena360 PROPERTIES
    C_STANDARD 17
    C_EXTENSIONS ON
)

target_compile_options(arena360 PRIVATE -Wall -Wextra -Werror)
xsdk_add_xex(arena360)

cmake_minimum_required(VERSION 3.25)
project(arena360 C)

option(ARENA360_BUILD_XBOX "Build the Xbox 360 title" ON)
option(BUILD_TESTING "Build host tests" OFF)

if(ARENA360_BUILD_XBOX)
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
endif()

if(BUILD_TESTING)
    if(CMAKE_CROSSCOMPILING)
        message(FATAL_ERROR "Host tests require a native compiler; use a separate build directory.")
    endif()
    enable_testing()
    add_executable(game_state_test tests/game_state_test.c src/game/game_state.c)
    target_include_directories(game_state_test PRIVATE src/game)
    set_target_properties(game_state_test PROPERTIES C_STANDARD 17 C_EXTENSIONS ON)
    target_compile_options(game_state_test PRIVATE -Wall -Wextra -Werror)
    add_test(NAME game_state COMMAND game_state_test)
endif()

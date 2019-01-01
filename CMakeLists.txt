cmake_minimum_required(VERSION 3.10)
project(NewGame)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME})

SET(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
SET(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
SET(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

ADD_SUBDIRECTORY(3rdparty/libSDL2pp)

INCLUDE_DIRECTORIES(
    ${SDL2PP_INCLUDE_DIRS}
    3rdparty/catch2)

ADD_EXECUTABLE(${PROJECT_NAME}
    src/main.cpp
    src/gameloop.cpp
    src/titlescreen.cpp
    src/level1.cpp
    src/simple_actor.cpp
    src/actor_arena.cpp
    src/new_game.cpp)

ADD_EXECUTABLE(${PROJECT_NAME}_test
    tests/test_main.cpp)

INSTALL(
    TARGETS ${PROJECT_NAME}
    DESTINATION bin)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/fonts
    DESTINATION bin)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/gfx
    DESTINATION bin)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${SDL2PP_LIBRARIES}
)

include(mingw64.cmake)
include(vs2015.cmake)
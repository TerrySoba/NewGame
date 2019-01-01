cmake_minimum_required(VERSION 3.10)
project(NewGame)


if(MSVC)
  add_compile_options(/W4 /WX)
else(MSVC)
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif(MSVC)


set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME})

SET(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
SET(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
SET(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

ADD_SUBDIRECTORY(3rdparty/libSDL2pp)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)

ADD_EXECUTABLE(${PROJECT_NAME}
    src/main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    NewGameLib)

INSTALL(
    TARGETS ${PROJECT_NAME}
    DESTINATION bin)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/fonts
    DESTINATION bin)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/gfx
    DESTINATION bin)

include(mingw64.cmake)
include(vs2015.cmake)

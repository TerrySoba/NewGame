cmake_minimum_required(VERSION 3.10)
project(NewGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  add_compile_options(/W4 /WX)
else(MSVC)
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif(MSVC)


set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME})

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

add_subdirectory(3rdparty/libSDL2pp)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(${PROJECT_NAME}
    src/main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    NewGameLib)

install(
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

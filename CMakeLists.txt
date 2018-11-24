cmake_minimum_required(VERSION 3.10)
project(NewGame)

SET(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
SET(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
SET(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

set(SDL2_PATH "C:/SDL2")

ADD_SUBDIRECTORY(3rdparty/libSDL2pp)

INCLUDE_DIRECTORIES(${SDL2PP_INCLUDE_DIRS})

ADD_EXECUTABLE(${PROJECT_NAME}
    src/main.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${SDL2PP_LIBRARIES}
)
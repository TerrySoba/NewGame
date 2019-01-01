
add_library(NewGameLib STATIC
    gameloop.cpp
    titlescreen.cpp
    level1.cpp
    simple_actor.cpp
    actor_arena.cpp
    new_game.cpp
    bullet_actor.cpp)

target_include_directories(NewGameLib PRIVATE
    ${SDL2PP_INCLUDE_DIRS}
    )

target_include_directories(NewGameLib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2PP_INCLUDE_DIRS}
    )

TARGET_LINK_LIBRARIES(NewGameLib
    ${SDL2PP_LIBRARIES}
    )


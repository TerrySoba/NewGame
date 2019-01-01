
ADD_EXECUTABLE(${PROJECT_NAME}_test
    test_main.cpp
    actor_collision_test.cpp)

target_include_directories(${PROJECT_NAME}_test PRIVATE
    ../3rdparty/catch2)

target_link_libraries(${PROJECT_NAME}_test
    NewGameLib)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(demo_menu demo_menu.c)
target_link_libraries(demo_menu ${STATE_LIBRARIES})

add_executable(basic basic.c)
target_link_libraries(basic ${STATE_LIBRARIES})
cmake_minimum_required(VERSION 3.0.0)
project(state)

add_library (state SHARED src/state.c)
add_library (state_static STATIC src/state.c)

set(STATE_LIBRARIES state)

install(TARGETS state DESTINATION lib)
install(TARGETS state_static DESTINATION lib)
install(FILES src/state.h DESTINATION include)

add_subdirectory(doc)
add_subdirectory(demos)

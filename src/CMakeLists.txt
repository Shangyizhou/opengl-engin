include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)
get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXECUTABLE_NAME} main.cc)
target_link_libraries(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/lib/libglfw3.a  ${PROJECT_SOURCE_DIR}/lib/libglad.a)
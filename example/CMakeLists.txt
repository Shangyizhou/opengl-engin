# 获取当前目录下的所有 .cc 文件
file(GLOB EXAMPLE_SOURCES "*.cc")

# 生成文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 遍历每个 .cc 文件
foreach(SOURCE_FILE ${EXAMPLE_SOURCES})
    # 获取文件名（无路径、无后缀）
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

    # 为当前源文件创建可执行文件
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    message(STATUS "Processing source file: ${SOURCE_FILE}")
    message(STATUS "Generating executable: ${EXECUTABLE_NAME}")

    # 链接需要的静态库或其他依赖
    target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_PATH}/libglfw3.a ${LIBRARY_PATH}/libglad.a)
endforeach()
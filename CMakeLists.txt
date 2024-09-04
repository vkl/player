# Specify the minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(player VERSION 1.0)

# Request C++ 11 standard features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ASAN_FLAGS "-fsanitize=address -g")

find_package(OpenSSL REQUIRED)
#option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
#add_subdirectory(lib)

# Compile the passed source files into an executable 
add_executable(player 
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/tls.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/cast_channel.pb-c.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/protobuf-c/protobuf-c.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cjson/cJSON.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cli.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cast_control.c")

target_link_libraries(player OpenSSL::SSL OpenSSL::Crypto)
include_directories(proto)
# Set the output directory for executables
set_target_properties(player
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")

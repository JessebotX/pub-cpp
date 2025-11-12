cmake_minimum_required(VERSION 3.25)
project(pub)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# add dependencies
include(cmake/CPM.cmake)

add_subdirectory(src)

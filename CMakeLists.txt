cmake_minimum_required(VERSION 3.13)
project(cnl_example)

set(CMAKE_CXX_STANDARD 17)

include(ExternalProject)
ExternalProject_Add(
        cnl
        URL "https://github.com/johnmcfarlane/cnl/archive/develop.zip"
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
)
find_package(Cnl PATHS ${CMAKE_CURRENT_BINARY_DIR})

add_executable(cnl_example main.cpp)
add_dependencies(cnl_example cnl)
target_include_directories(cnl_example PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include)
target_compile_options(cnl_example PRIVATE "-Werror" "-Wall" "-Wextra")

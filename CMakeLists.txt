cmake_minimum_required(VERSION 3.12.4)
project(cnl_example)

set(CMAKE_CXX_STANDARD 17)

find_package(cnl REQUIRED)

add_executable(cnl_example main.cpp)
target_compile_options(cnl_example PRIVATE "-Werror" "-Wall" "-Wextra")
target_link_libraries(cnl_example cnl::cnl)

include(CTest)
add_test(test-output bash -c "./cnl_example | perl -0777 -e '$n = <>; $h = <>; exit(index($h,$n)<0)' - '${PROJECT_SOURCE_DIR}/README.md'")

if (CMAKE_HOST_WIN32)
# need CMake 3.25.0+ for IntelLLVM support of target link properties on Windows
cmake_minimum_required(VERSION 3.25)
else()
# CMake 3.20.5 is the minimum recommended for IntelLLVM on Linux
cmake_minimum_required(VERSION 3.20.5)
endif()

project(example
  LANGUAGES CXX
  DESCRIPTION "Hello world from GPU"
)

add_compile_options(-v)

find_package(IntelSYCL REQUIRED)

add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_sycl_to_target(TARGET example SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS example DESTINATION .)

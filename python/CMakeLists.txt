cmake_minimum_required(VERSION 3.26)

project(hello)

# find_package(PythonExtensions REQUIRED)
find_package(Python 3.9 REQUIRED
  COMPONENTS Interpreter Development.Module)
find_package(IntelSYCL REQUIRED)

add_compile_options(-v)

python_add_library(_hello MODULE hello/_hello.cxx)
# python_extension_module(_hello)
add_sycl_to_target(TARGET _hello SOURCES hello/_hello.cxx)

install(TARGETS _hello LIBRARY DESTINATION hello)
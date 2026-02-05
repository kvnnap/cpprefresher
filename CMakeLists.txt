cmake_minimum_required(VERSION 4.2.3)

# Set experimental flag to enable `import std` support from CMake.
# This must be enabled before C++ language support.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.
  "d0edc3af-4c50-42ea-a356-e2862fe7a444")

set(CMAKE_CXX_EXTENSIONS OFF)

project(hello)

add_executable(hello main.cpp shape.cpp separated_module.cpp split_extension_module.cpp)
target_sources(hello PRIVATE FILE_SET CXX_MODULES FILES test_module.cppm another_module.cppm shape_module.cppm separated_module.cppm split_main_module.cppm)
set_target_properties(hello PROPERTIES 
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_MODULE_STD ON
    # CXX_SCAN_FOR_MODULES ON
    COMPILE_WARNING_AS_ERROR ON
    DEBUG_POSTFIX "_d"
)

target_compile_options(hello PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4> # Should add /WX too
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic>
)




cmake_minimum_required(VERSION 2.8)

include_directories(".")

set (EXAMPLE_00_EXECUTABLE example-00)

ouroboros_wrap_module (
  prompt
  lua
  ${CMAKE_CURRENT_LIST_DIR}/src
  EXAMPLE_00_LUA_GENERATED_SRC
  src/prompt.h
)

ouroboros_wrap_module (
  prompt
  python
  ${CMAKE_CURRENT_LIST_DIR}/src
  EXAMPLE_00_PYTHON_GENERATED_SRC
  src/prompt.h
)

set (
  EXAMPLE_00_GENERATED_SRC
  ${EXAMPLE_00_LUA_GENERATED_SRC}
  ${EXAMPLE_00_PYTHON_GENERATED_SRC}
)

set (
  EXAMPLE_00_SRC
  src/main.cxx
  src/prompt.h
  src/prompt.cxx
)

message (STATUS ${EXAMPLE_00_GENERATED_SRC})

set_source_files_properties (
  ${EXAMPLE_00_GENERATED_SRC}
  PROPERTIES
  GENERATED 1
  COMPILE_FLAGS -std=gnu++0x
)

add_definitions (-std=gnu++0x)

add_executable (
  ${EXAMPLE_00_EXECUTABLE}
  ${EXAMPLE_00_SRC}
  ${EXAMPLE_00_GENERATED_SRC}
)

target_link_libraries (
  ${EXAMPLE_00_EXECUTABLE}
  libouroboros
  libouroboros-lua
  libouroboros-python
)


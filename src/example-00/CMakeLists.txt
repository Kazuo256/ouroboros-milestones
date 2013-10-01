
cmake_minimum_required(VERSION 2.8)

include_directories("src")

set (EXAMPLE_00_EXECUTABLE example-00)

ouroboros_wrap_module (
  prompt
  ${CMAKE_CURRENT_LIST_DIR}/src
  EXAMPLE_00_GENERATED_SRC
)

set (
  EXAMPLE_00_SRC
  src/main.cxx
  src/prompt.h
  src/prompt.cxx
)

message (STATUS ${EXAMPLE_00_GENERATED_SRC})

add_custom_command (
  OUTPUT ${EXAMPLE_00_GENERATED_SRC}
  COMMAND opwig
  ARGS    --module-name=prompt prompt.h
  DEPENDS src/prompt.h opwig
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src
)

set_source_files_properties (
  ${EXAMPLE_00_GENERATED_SRC}
  PROPERTIES
  GENERATED 1
)

set_source_files_properties (
  ${EXAMPLE_00_SRC}
  ${EXAMPLE_00_GENERATED_SRC}
  PROPERTIES
  COMPILE_FLAGS -std=gnu++0x
)

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


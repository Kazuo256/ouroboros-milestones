
cmake_minimum_required(VERSION 2.8)

include_directories("src")

set (EXAMPLE_00_EXECUTABLE example-00)

set (
  EXAMPLE_00_SRC
  src/main.cxx
  src/prompt.h
  src/prompt.cxx
)

set (
  EXAMPLE_00_GENERATED_SRC
  src/Lua_prompt_wrap.cxx
  src/Python_prompt_wrap.cxx
)

find_package (PythonLibs 2.6)
include_directories (${PYTHON_INCLUDE_DIRS})

find_package (Lua51)
include_directories (${LUA_INCLUDE_DIR})

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


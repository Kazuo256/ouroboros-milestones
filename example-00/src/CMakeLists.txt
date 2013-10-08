
set (EXAMPLE_00_EXECUTABLE example-00)

ouroboros_wrap_module (
  prompt
  lua
  ${CMAKE_CURRENT_LIST_DIR}
  EXAMPLE_00_LUA_GENERATED_SRC
  prompt.h
)

ouroboros_wrap_module (
  prompt
  python
  ${CMAKE_CURRENT_LIST_DIR}
  EXAMPLE_00_PYTHON_GENERATED_SRC
  prompt.h
)

set (
  EXAMPLE_00_GENERATED_SRC
  ${EXAMPLE_00_LUA_GENERATED_SRC}
  ${EXAMPLE_00_PYTHON_GENERATED_SRC}
)

set (
  EXAMPLE_00_SRC
  main.cxx
  prompt.h
  prompt.cxx
)

set_source_files_properties (
  ${EXAMPLE_00_SRC}
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


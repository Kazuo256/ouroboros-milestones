
set (EXAMPLE_EXECUTABLE example-02)

ouroboros_wrap_module (
  prompt
  lua
  ${CMAKE_CURRENT_LIST_DIR}
  EXAMPLE_LUA_GENERATED_SRC
  out.h
  input.h
)

ouroboros_wrap_module (
  prompt
  python
  ${CMAKE_CURRENT_LIST_DIR}
  EXAMPLE_PYTHON_GENERATED_SRC
  out.h
  input.h
)

set (
  EXAMPLE_GENERATED_SRC
  ${EXAMPLE_LUA_GENERATED_SRC}
  ${EXAMPLE_PYTHON_GENERATED_SRC}
)

set (
  EXAMPLE_SRC
  main.cxx
  out.h
  out.cxx
  input.h
  input.cxx
)

set_source_files_properties (
  ${EXAMPLE_SRC}
  PROPERTIES
  COMPILE_FLAGS -std=gnu++0x
)

add_executable (
  ${EXAMPLE_EXECUTABLE}
  ${EXAMPLE_SRC}
  ${EXAMPLE_GENERATED_SRC}
)

target_link_libraries (
  ${EXAMPLE_EXECUTABLE}
  libouroboros
  libouroboros-lua
  libouroboros-python
)


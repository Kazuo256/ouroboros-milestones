
set (MILESTONE_EXECUTABLE milestone-05)

ouroboros_wrap_module (
  prompt
  lua
  ${CMAKE_CURRENT_LIST_DIR}
  MILESTONE_LUA_GENERATED_SRC
  out.h
  input.h
)

ouroboros_wrap_module (
  prompt
  python
  ${CMAKE_CURRENT_LIST_DIR}
  MILESTONE_PYTHON_GENERATED_SRC
  out.h
  input.h
)

set (
  MILESTONE_GENERATED_SRC
  ${MILESTONE_LUA_GENERATED_SRC}
  ${MILESTONE_PYTHON_GENERATED_SRC}
)

set (
  MILESTONE_SRC
  main.cxx
  out.h
  out.cxx
  input.h
  input.cxx
)

set_source_files_properties (
  ${MILESTONE_SRC}
  PROPERTIES
  COMPILE_FLAGS -std=gnu++0x
)

add_executable (
  ${MILESTONE_EXECUTABLE}
  ${MILESTONE_SRC}
  ${MILESTONE_GENERATED_SRC}
)

target_link_libraries (
  ${MILESTONE_EXECUTABLE}
  libouroboros
  libouroboros-lua
  libouroboros-python
)



set (MILESTONE_EXECUTABLE milestone-06)

set (
  MILESTONE_SRC
  main.cxx
)

find_package (Lua51)
include_directories (${LUA_INCLUDE_DIR})

set_source_files_properties (
  ${MILESTONE_SRC}
  PROPERTIES
  COMPILE_FLAGS -std=gnu++0x
)

add_executable (
  ${MILESTONE_EXECUTABLE}
  ${MILESTONE_SRC}
)

target_link_libraries (
  ${MILESTONE_EXECUTABLE}
  libouroboros
  libouroboros-lua
)


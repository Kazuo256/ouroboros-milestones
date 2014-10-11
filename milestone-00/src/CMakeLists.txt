
set (MILESTONE_EXECUTABLE milestone-00)

add_library(${MILESTONE_EXECUTABLE}-prompt prompt.h prompt.cxx)

ouroboros_export_metadata(${MILESTONE_EXECUTABLE}-prompt prompt.h)
ouroboros_create_wrappers(${MILESTONE_EXECUTABLE}-prompt lua)
ouroboros_create_wrappers(${MILESTONE_EXECUTABLE}-prompt python)

set (
  MILESTONE_SRC
  main.cxx
)

if (UNIX OR MINGW)
    set_source_files_properties (
      ${MILESTONE_SRC}
      PROPERTIES
      COMPILE_FLAGS -std=gnu++0x
    )
endif()
   

add_executable (${MILESTONE_EXECUTABLE} ${MILESTONE_SRC})

target_link_libraries (${MILESTONE_EXECUTABLE}
  libouroboros
  libouroboros-lua
  libouroboros-python
  ${MILESTONE_EXECUTABLE}-prompt
  ${MILESTONE_EXECUTABLE}-prompt-lua
  ${MILESTONE_EXECUTABLE}-prompt-python
)


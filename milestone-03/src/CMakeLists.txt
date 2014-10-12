
set (MILESTONE_EXECUTABLE milestone-03)

set ( PROMPT_SRC
  out.cxx
  input.cxx
)

set ( PROMPT_HEADERS
  out.h
  input.h
)

add_library(${MILESTONE_EXECUTABLE}-prompt ${PROMPT_HEADERS} ${PROMPT_SRC})
set_target_properties (${MILESTONE_EXECUTABLE}-prompt PROPERTIES FOLDER ${MILESTONE_EXECUTABLE})

ouroboros_export_metadata(${MILESTONE_EXECUTABLE}-prompt ${PROMPT_HEADERS})
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
set_target_properties (${MILESTONE_EXECUTABLE} PROPERTIES FOLDER ${MILESTONE_EXECUTABLE})

target_link_libraries (${MILESTONE_EXECUTABLE}
  libouroboros
  libouroboros-lua
  libouroboros-python
  ${MILESTONE_EXECUTABLE}-prompt
  ${MILESTONE_EXECUTABLE}-prompt-lua
  ${MILESTONE_EXECUTABLE}-prompt-python
)


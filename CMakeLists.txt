
cmake_minimum_required (VERSION 2.8)

add_subdirectory (externals/ouroboros EXCLUDE_FROM_ALL)

include_directories (${OUROBOROS_INCLUDE_DIR})
include (${OUROBOROS_WRAP_HELPER})

add_subdirectory (src)



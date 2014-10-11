
cmake_minimum_required (VERSION 2.8)

add_subdirectory (externals/ouroboros)

include_directories (${OUROBOROS_INCLUDE_DIR})
include (externals/ouroboros/cmake/wrap_helper.cmake)

add_subdirectory (milestone-00)
add_subdirectory (milestone-01)
add_subdirectory (milestone-02)
add_subdirectory (milestone-03)
add_subdirectory (milestone-05)


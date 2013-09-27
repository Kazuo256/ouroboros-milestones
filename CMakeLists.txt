
cmake_minimum_required (VERSION 2.8)

add_subdirectory (externals/ouroboros EXCLUDE_FROM_ALL)

include_directories (externals/ouroboros/src)
add_definitions (-std=gnu++0x)
message (STATUS ${CMAKE_MODULE_PATH})

add_subdirectory (src)



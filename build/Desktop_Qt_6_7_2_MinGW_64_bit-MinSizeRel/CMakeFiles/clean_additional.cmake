# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\random_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\random_autogen.dir\\ParseCache.txt"
  "random_autogen"
  )
endif()

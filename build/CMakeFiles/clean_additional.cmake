# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\mica_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mica_autogen.dir\\ParseCache.txt"
  "mica_autogen"
  )
endif()

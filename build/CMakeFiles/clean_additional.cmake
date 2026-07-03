# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/MarioKartBuildAnalyzer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MarioKartBuildAnalyzer_autogen.dir/ParseCache.txt"
  "MarioKartBuildAnalyzer_autogen"
  )
endif()

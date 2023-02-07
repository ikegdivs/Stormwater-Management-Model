#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "swmm-output" for configuration "MinSizeRel"
set_property(TARGET swmm-output APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(swmm-output PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "${_IMPORT_PREFIX}/lib/swmm-output.lib"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/swmm-output.dll"
  )

list(APPEND _cmake_import_check_targets swmm-output )
list(APPEND _cmake_import_check_files_for_swmm-output "${_IMPORT_PREFIX}/lib/swmm-output.lib" "${_IMPORT_PREFIX}/bin/swmm-output.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

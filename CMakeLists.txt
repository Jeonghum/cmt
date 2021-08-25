cmake_minimum_required (VERSION 3.10)

project (Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# should we use our own math functions?
option (USE_MYMATH
  "Use tutorial provided math implementation" ON)

configure_file (TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library?
#
if (USE_MYMATH)
  add_subdirectory (MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif ()

# add the executable
add_executable (Tutorial tutorial.cxx)

target_link_libraries (Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
  "${PROJECT_BINARY_DIR}"
  )


# clean.cmake
file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/CMakeFiles")
file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/Testing")
file(REMOVE "${CMAKE_BINARY_DIR}/CMakeCache.txt")
file(REMOVE "${CMAKE_BINARY_DIR}/Makefile")
file(REMOVE "${CMAKE_BINARY_DIR}/cmake_install.cmake")
file(REMOVE "${CMAKE_BINARY_DIR}/CTestTestfile.cmake")
file(REMOVE "${CMAKE_BINARY_DIR}/DartConfiguration.tcl")
file(REMOVE "${CMAKE_BINARY_DIR}/project")
file(REMOVE "${CMAKE_BINARY_DIR}/brute_force")
file(REMOVE "${CMAKE_BINARY_DIR}/allTests")
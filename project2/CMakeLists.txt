cmake_minimum_required(VERSION 3.0)

project(project2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Organize source files into directories
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB HEADER_FILES "include/*.hpp")
file(GLOB TEMPLATE_FILES "templates/*.tpp")
file(GLOB TEST_FILES "tests/*.cpp")

# Group files for IDEs
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${HEADER_FILES})
source_group("Template Files" FILES ${TEMPLATE_FILES})
source_group("Test Files" FILES ${TEST_FILES})

# Compiler flags (optional)
add_compile_options(-Wall -Wextra -pedantic)

# Create the executable
add_executable(project2 ${SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})

# Create the tests executable and link it with project source files
add_executable(allTests ${TEST_FILES} ${HEADER_FILES})

# Set target-specific include directories
target_include_directories(project2 PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(allTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Run tests using Catch2
include(CTest)

# Run tests using catch.hpp
add_test(NAME CatchTests COMMAND allTests)

# Set the working directory for the test
set_tests_properties(CatchTests PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# Create a custom target for cleaning
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/clean.cmake"
    COMMENT "Cleaning build files"
)
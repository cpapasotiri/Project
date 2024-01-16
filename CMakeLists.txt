cmake_minimum_required(VERSION 3.0)

project(project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Organize source files into directories
file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/project/*.cpp")
file(GLOB_RECURSE BRUTE_FORCE_SOURCE_FILES "src/brute_force/*.cpp")
file(GLOB COMMON_SOURCE_FILES "src/common/*.cpp")
file(GLOB HEADER_FILES "include/*.hpp")
file(GLOB TEMPLATE_FILES "templates/*.tpp")
file(GLOB TEST_FILES "tests/*.cpp")

# Group files for IDEs
source_group("Source Files" FILES ${PROJECT_SOURCE_FILES} ${BRUTE_FORCE_SOURCE_FILES} ${COMMON_SOURCE_FILES})
source_group("Header Files" FILES ${HEADER_FILES})
source_group("Template Files" FILES ${TEMPLATE_FILES})
source_group("Test Files" FILES ${TEST_FILES})

# Compiler flags
add_compile_options(-Wall -Wextra -pedantic)

# Create the project executable
add_executable(project ${PROJECT_SOURCE_FILES} ${COMMON_SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})

# Create the brute_force executable
add_executable(brute_force ${BRUTE_FORCE_SOURCE_FILES} ${COMMON_SOURCE_FILES} ${HEADER_FILES} ${TEMPLATE_FILES})

# Create the tests executable and link it with project source files
add_executable(allTests ${TEST_FILES} ${COMMON_SOURCE_FILES} ${HEADER_FILES})

# Set target-specific include directories
target_include_directories(project PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(brute_force PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(allTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link against the pthread library
find_package(Threads REQUIRED)
target_link_libraries(project PRIVATE Threads::Threads)
target_link_libraries(brute_force PRIVATE Threads::Threads)
target_link_libraries(allTests PRIVATE Threads::Threads)

# Run tests using Catch2
include(CTest)

# Run tests using catch.hpp
add_test(NAME CatchTests COMMAND allTests --success)

# Set the working directory for the test
set_tests_properties(CatchTests PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# Enable verbose output for tests
set(CTEST_ARGS "--verbose")

# Create a custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} ${CTEST_ARGS}
    DEPENDS allTests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all tests"
)

# Create a custom target for cleaning
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/clean.cmake"
    COMMENT "Cleaning build files"
)
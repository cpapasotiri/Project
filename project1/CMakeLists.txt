cmake_minimum_required(VERSION 3.0)

project(project1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(include)

# Add source files
set(SOURCE_FILES
    src/main.cpp
)

# Add template implementation files
set(TEMPLATE_FILES
    templates/DLL.tpp
    templates/graph.tpp
    templates/input.tpp
    templates/vector.tpp
)

# Create the executable
add_executable(project1 ${SOURCE_FILES} ${TEMPLATE_FILES})
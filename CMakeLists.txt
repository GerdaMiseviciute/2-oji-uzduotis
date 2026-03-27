cmake_minimum_required(VERSION 3.10)    # Minimum CMake version
project(Objektinis-programavimas VERSION 1.0)          # Project name and version

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(Objektinis-programavimas main.cpp funkcijos.cpp)
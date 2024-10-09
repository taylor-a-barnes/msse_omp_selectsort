cmake_minimum_required(VERSION 3.14)

# Project name and version
project(OpenMPSort VERSION 1.0
	      DESCRIPTION "Sort operation using OpenMP"
		  LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add the executable
add_executable(selectsort src/main.cpp)

# Find OpenMP
find_package(OpenMP REQUIRED)
target_link_libraries(selectsort PUBLIC OpenMP::OpenMP_CXX)


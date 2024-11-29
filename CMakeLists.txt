# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.31.1)

# Define the project name and version
project(opengl_project
    VERSION 1.0.0
    DESCRIPTION "Just an opengl window"
    LANGUAGES C CXX
)

# Set the C++ standard to C11
set(CMAKE_CXX_STANDARD 11) # Requires C11 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Assume the default OS bitness is 32-bit
set(OSBitness 32)

# Check if the platform is 64-bit and update the variable accordingly
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OBBitness 64)
endif()

# Define the output directory structure for binaries
# Output paths depend on system name, bitness, and build type
set(FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs") # static libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}") # shared libaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}") # executabel files

# Specify the source files for the main executable
set(SOURCES src/main.cpp)

# Add the main executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Add GLFW dependency
add_subdirectory(libs/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# Link OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

# Include directories for GLFW
target_include_directories(${PROJECT_NAME} PRIVATE libs/glfw/include)
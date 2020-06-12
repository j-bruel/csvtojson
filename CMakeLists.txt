##
## Cmake minimum version
##
cmake_minimum_required(VERSION 3.1)

##
## Project version.
##
set(csvtojson_VERSION_MAJOR 1)
set(csvtojson_VERSION_MINOR 0)
set(csvtojson_VERSION_PATCH 0)
set(csvtojson_VERSION "${csvtojson_VERSION_MAJOR}.${csvtojson_VERSION_MINOR}.${csvtojson_VERSION_PATCH}")

##
## Project description.
##
set(PROJECT_DESCRIPTION "\"Askia technical test.\"")

##
## Project Name
##
project(csvtojson VERSION ${csvtojson_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION})

##
## Project name, use for Doxygen.
##
set(PROJ_NAME "\"${PROJECT_NAME}\"")

##
## C++ standard compilation
##
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##
## Set output directories.
##
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

##
## Include headers directory.
##
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/jsoncons-0.153.1/include)

##
## Cmake build configuration options.
##
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS  "Setting build type to 'Debug' as no build type was specified.")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the build type (Debug/Release)" FORCE)
endif (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    ##
    ## Set Linux compilation flag.
    ##
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    ##
    ## Set Windows compilation flag.
    ##
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

##
## Sources files
##
file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

##
## Generation static library.
##
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_FILES})
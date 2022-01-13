#--------------------------------------------------
#   syntax samples
#--------------------------------------------------
#default include directories (legacy, cmake 2.8.10 or older)
#   include_directories(<directory> [<directory> ...])

#default include directories
#!!! add this AFTER specifying the target !!!
#   target_include_directories(<target> PRIVATE <directory> [<directory> ...])


#variable reference syntax:
#   ${<variable>}

#-----
#useful variables:
#-----
#project build configurations
#   DEBUG
#   RELEASE
#   MINSIZEREL
#   RELWITHDEBINFO

#   PROJECT_SOURCE_DIR
#   CMAKE_BINARY_DIR
#   CMAKE_RUNTIME_OUTPUT_DIRECTORY  # for targets (executables and DLL-s)
#   CMAKE_ARCHIVE_OUTPUT_DIRECTORY  # for .a files (static libs)
#   CMAKE_LIBRARY_OUTPUT_DIRECTORY  # ?????

#   EXECUTABLE_OUTPUT_PATH          # !!! this is old, don't use !!!


#-----
#define version
#note: ALWAYS call before 'project()' call!
#   cmake_minimum_required(VERSION 3.5)

#project(<name> [<language-name>...])
#   sets project name
#       has to be one direct all at the top level AFTER cmake_minimum_required() call
#   defines the enabled languages (C and CXX default)
#       C, CXX (i.e. C++), CUDA, OBJC (i.e. Objective-C), OBJCXX, Fortran, ISPC, and ASM.
#   and sets variables
#      PROJECT_NAME
#      CMAKE_PROJECT_NAME
#      PROJECT_SOURCE_DIR
#         <PROJECT-NAME>_SOURCE_DIR
#      PROJECT_BINARY_DIR
#         <PROJECT-NAME>_BINARY_DIR

#create executable as target
#   add_executable(<executable> <sourcefile> [<sourcefile> ...] [<header> ...])

#create lib as target
#   add_library(<library> <sourcefile> [<sourcefile> ...] [<header> ...])

#create DLL as target
#   add_library(<library> SHARED <sourcefile> [<sourcefile> ...] [<header> ...])

#link lib-s and DLL-s to executable
#   target_link_libraries(<target> <library> [<library> ...])


#set up target build directory
#   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#   set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#   set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#OR
#   set_target_properties( targets...
#       PROPERTIES
#       ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#       LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#       RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#   )

#   You can append _[CONFIG] to the variable/property name to make the output directory apply to a specific configuration
#       eg: CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG
#           CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE



#cmake -DCMAKE_BUILD_TYPE=Debug path/to/source
#cmake -DCMAKE_BUILD_TYPE=Release path/to/source
#CMAKE_BUILD_TYPE

#-----
#fill out later
#-----

# include hierarchies
#   visibility
#     PUBLIC | PRIVATE | INTERFACE
#     relevant, when targets refer eachother as dependencies

#   interface includes
#     interface_include_directories( ... )

# install target
#   install(TARGETS <target>)



#--------------------------------------------------
#   Project
#--------------------------------------------------

cmake_minimum_required(VERSION 3.5)

project(cmaketest LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_library(applib src/testclass.cpp include/testclass.h)
add_library(applib2 SHARED src/testclass.cpp include/testclass.h)

#add_executable(cmaketest src/main.cpp)
add_executable(cmaketest src/main.cpp src/testclass.cpp include/testclass.h)
target_include_directories(cmaketest PRIVATE ${PROJECT_SOURCE_DIR}/include)
#target_link_libraries(cmaketest applib)

#cmake_minimum_required(VERSION 2.4)
#project(hello_world)
#include_directories(${PROJECT_SOURCE_DIR})
#add_library(applib foo.cpp)
#add_executable(app main.cpp)
#target_link_libraries(app applib)


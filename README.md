# Morpheus
A simplistic implementation of a group expense splitting algorithm.
Modularized for C++ and Python

### ARCHITECTURE:

1. Library will be written in C++ and compiled as a shared object.
2. PHP(for web-based interface), iOS and Android-NDK wrappers on top of the C++ library

## To Do
1. Need to add main.cpp in C++ Directory to run the driver program.
2. Check for errors in other files.
3. make or make all will generate the library and binary.
4. Just run make clean to remove the generated obj files.

## C++ Development Wiki:

#### 1. Directory structure
- *libraries/* holds a set of generic modules that provide a specific functionality and can be used by other modules
- *inc/* and *src/* hold the core application code headers and source respectively
- *build/* is dynamically generated during build time and contains generated object files, debug info and final binary
- *unittests/* holds a complete set of test cases for isolated testing of modules and libraries

#### 2. Feature development guidelines

cmake_minimum_required(VERSION 3.10)

project(server C)

# Build the static library from all lib sources
#add_library(lib
 #   lib/file.c
  #  lib/http.c
#)

# Build the executable from main.c
#add_executable(server main.c)

# Link the executable with the static library
#target_link_libraries(server PRIVATE lib)

# Link pthread for threading functions
#target_link_libraries(server PRIVATE pthread)

add_executable(test test.c)
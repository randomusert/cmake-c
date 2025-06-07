cmake_minimum_required(VERSION 3.10) #tell cmake the minmum version of cmake it is allowed to use. DO NOT REMOVE!

project(echo C) # tell cmake what project it compiles
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(echo main.c) #tell cmake to build the spesified binary from the c file provided in there

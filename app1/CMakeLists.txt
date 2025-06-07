cmake_minimum_required(VERSION 3.10) #tell cmake the minmum version of cmake it is allowed to use. DO NOT REMOVE!

project(app1 C) # tell cmake what project it compiles

add_executable(app1 main.c) #tell cmake to build the spesified binary from the c file provided in there

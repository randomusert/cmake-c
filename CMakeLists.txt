cmake_minimum_required(VERSION 3.10)

# set projects for the top level cmakelists file
project(cmake-c C)

# add projects to build
add_subdirectory(app1)
add_subdirectory(echo)
add_subdirectory(server)
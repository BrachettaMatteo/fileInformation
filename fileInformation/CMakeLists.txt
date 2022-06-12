#minimum version
cmake_minimum_required(VERSION 2.4)
#name of project
project(fileInformation)
#add source directory for *.h
include_directories(${PROJECT_SOURCE_DIR}/library)

#gcc main.c -o fileInformation
add_executable(fileInformation ./src/utility.c ./src/opzioni.c ./src/config.c ./src/main.c )
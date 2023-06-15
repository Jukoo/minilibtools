cmake_minimum_required (VERSION 3.26) 
project (subp VERSION 1.0) 
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True) 

set(SOURCES  main.c  subprocess.c)

add_executable(${PROJECT_NAME} ${SOURCES})

cmake_minimum_required (VERSION 3.26) 
project (subproc VERSION 1.0)   

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True) 

set(source src/subprocess.c) 

add_library(${PROJECT_NAME} SHARED ${source}) 

target_include_directories(${PROJECT_NAME} PRIVATE include) 

set_target_properties(${PROJECT_NAME}  PROPERTIES  VERSION  ${PROJECT_VERSION}) 
set_target_properties(${PROJECT_NAME}  PROPERTIES  SOVERSION ${PROJECT_VERSION_MAJOR}) 
set_target_properties(${PROJECT_NAME}  PROPERTIES  PUBLIC_HEADER ./include/subprocess.h) 

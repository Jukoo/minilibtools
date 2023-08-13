cmake_minimum_required(VERSION 3.26) 
project(app.elfbin VERSION 1.0) 

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)  

string(ASCII 27 Escape)
if(DBG)  
  message("\t ${Escape}[1;32m +>> Enable Debug Symbol ${Escape}[0m")  
  set(CMAKE_BUILD_TYPE Debug) 
endif()

set(extlibloc ../out)

if(LD_LIBLOC)
  set(extlibloc  ${LD_LIBLOC}) 
endif() 

include_directories(../include) 
link_directories(../out) 

add_executable(${PROJECT_NAME} main.c) 
target_link_libraries(${PROJECT_NAME}  subproc)

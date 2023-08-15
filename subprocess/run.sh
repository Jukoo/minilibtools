#!/bin/bash 




cmake  --build out 
cmake  --build app/build 

./app/build/app.elfbin

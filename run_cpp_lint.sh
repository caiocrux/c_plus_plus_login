#!/bin/bash

cpplint --root=. --recursive ./src ./include 

if [ $? -eq 0 ];
then
    echo "executed without any C++ Code Guide Style Error!"
else
    echo "found some Style Error!"
fi


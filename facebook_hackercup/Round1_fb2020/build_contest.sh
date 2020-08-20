#!/usr/bin/bash

mkdir -p A1 A2 A3
touch A1/A1.txt A2/A2.txt A3/A3.txt 
touch A1/A1.cpp A2/A2.cpp A3/A3.cpp
touch A1/test.inp A2/test.inp A3/test.inp
touch A1/test.txt A2/test.txt A3/test.txt

for c in {B..C};
do
    mkdir -p $c
    touch $c/$c.cpp
    touch $c/$c.txt
    touch $c/test.inp
    touch $c/test.txt
done

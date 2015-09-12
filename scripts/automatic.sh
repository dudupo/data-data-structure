#!/bin/bash

if [ "$1" == "makec" ]
	then 
	for i in "./code/c/*_main.c"
	do
		j=`basename $i`
		gcc -std=c11 $i -o ./bin/$j
	done
	exit 1
fi

if [ "$1" == "runc" ]
	then
	for i in "./bin/*_main.c"
	do 
		$i
	done
	exit 1  
fi

if [ "$1" == "makecpp" ]
	then

	for i in "./code/cpp/*_main.cpp"
	do
		j=`basename $i`
		g++ --std=c++11 $i -o ./bin/$j
	done
	exit 1
fi

if [ "$1" == "runcpp" ]
	then
	for i in "./bin/*_main.cpp"
	do 
		$i
	done
	exit 1  
fi

#if []

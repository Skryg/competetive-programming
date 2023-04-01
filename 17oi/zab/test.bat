#!/bin/bash

for(( i = 1; i < 5; i++ ))
do
	./zab < ./in/zab${i}ocen.in > temp.out
	if diff -w ./temp.out ./out/zab${i}ocen.out  
	then
		echo "OK"
	fi
done

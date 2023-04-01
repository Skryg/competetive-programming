#!/bin/bash

for i in $(seq 1 47)
do
	./main < ./in/mop$i.in > ./temp.out
	diff -b ./temp.out ./out/mop$i.out || break
done

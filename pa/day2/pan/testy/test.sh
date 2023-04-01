#!/bin/bash

for i in $(seq 1 200)
do
	./main < ./in/$i.in > ./temp.out
	echo $i
	diff -b ./temp.out ./out/$i.out || break
done


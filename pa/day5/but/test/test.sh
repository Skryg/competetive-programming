#!/bin/bash

for i in $(seq 0 100); do
	echo $i
	./main < ./in/$i.in > ./temp.out
	diff -b ./temp.out ./out/$i.out || break
done


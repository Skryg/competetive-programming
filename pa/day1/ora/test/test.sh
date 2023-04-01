#!/bin/bash

for i in $(seq 1 1000)
do
	./main < ./in/$i.in > ./temp.out
	diff -b ./temp.out ./out/$i.out
done


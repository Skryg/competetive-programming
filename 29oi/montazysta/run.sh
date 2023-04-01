#!/bin/bash

sudo chmod +x ./$1 
>$1.time
for (( c=$2; c<=$3; c++ ))
do
	( time ./$1 < ./in/$c.in > ./temp.out) 2>> $1.time
	echo $c
	diff -b ./out/$c.out ./temp.out || break
done
grep -e "user" ./$1.time | sort -r > ./$1.final
echo "Done."

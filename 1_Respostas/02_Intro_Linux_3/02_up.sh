#!/bin/bash
N=$1
echo "$N"
while [ $N -gt "0" ]
do
	cd ..
	N=$(($N-1))
	echo "$N"
done

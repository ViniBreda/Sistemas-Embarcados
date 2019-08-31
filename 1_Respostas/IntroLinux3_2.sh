#!/bin/bash
echo Calendários:
while [ "$#" -gt "0" ]
do
	mes=$1
	shift
	ano=$1
	shift
	cal "$mes" "$ano"
done


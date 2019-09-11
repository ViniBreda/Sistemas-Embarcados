#!/bin/bash
echo Calendários:
ANO=$(date +%G)
FIM=$(($ANO-10))
while [ "$ANO" -gt "$FIM" ]
do
	mes=$1
	cal "$mes" "$ANO"
	ANO=$((ANO-1))
done


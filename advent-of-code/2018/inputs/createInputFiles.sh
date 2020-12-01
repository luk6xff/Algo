#!/bin/bash
FILE_NAME='input'

for day in {1..25}
do
	if $day -lt 10
	then
		touch "$FILE_NAME0$day.txt"
	else
		touch "$FILE_NAME$day.txt"
	fi
done

#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Please enter valid argument"
	echo "For more details, refer readme :)"
	echo "We will exit now"
	exit 1
fi
iterations=$1
echo We will have "$iterations" cycles
i=1
#while [ $i -lt $interations ] || [ $i -eq $interations ]
while true
do
	if [ "$i" -gt "$iterations" ]
	then
		echo "FINISHED"
		exit 1
	fi
	echo "$i WORK"
	sleep 1
	num=$(( i%4 ))
	if [ "$num" -eq "0" ]
	then
		echo "$i BIG BREAK"
		sleep 3
	else
		echo "$i BREAK"
		sleep 1
	fi
	i=$(( i+1 ))
done

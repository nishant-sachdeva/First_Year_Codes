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
while true
do
	if [ "$i" -gt "$iterations" ]
	then
		echo "FINISHED"
		exit 1
	fi
	notify-send "$i WORK" "`echo "get to work plisss, your next 25 mins timer is set" `"
	echo "$i WORK"
	sleep 1500
	num=$(( i%4 ))
	if [ "$num" -eq "0" ]
	then
		notify-send "$i BREAK!!!!!!" "`echo "You can have your break now, your next 5 mins timer is set"
		echo "In keeping with the four interations rule, you get an extra break of 15 mins apart from the normal time"
		echo "Have fun in the 20 mins long big break,  SEE YA!!" `"
		echo "$i BIG BREAK"
		sleep 1200
	else
		notify-send "$i BREAK!!!!!!" "`echo "You can have your break now, your next 5 mins timer is set" `"
		echo "$i BREAK"
		sleep 300
	fi
	i=$(( i+1 ))
done

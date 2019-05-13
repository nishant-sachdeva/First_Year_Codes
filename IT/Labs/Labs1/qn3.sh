#!/bin/bash

a=0
b=1
rem=1
while [ $b -lt 100 ]
do
	remm=`expr $b % 2`
	if [ $remm -eq $rem ]
	then
		echo "$b"
	fi
	temp=`expr $a + $b`
	a=$b
	b=$temp
done
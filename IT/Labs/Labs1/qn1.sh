#!bin/bash

num=$#
b=2
if [ $num -ne $b ]
then
	echo "error : wrong number of arguments"
else
	ans=0
	for n in $*
	do
		ans=`expr $ans + $n`
	done
	echo "the sum of the numbers is $ans"
fi


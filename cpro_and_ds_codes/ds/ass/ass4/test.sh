#!/bin/bash

i=$1
# at max 10000 iterations
echo $1

if [[ $i -eq 10000 ]]
then
	exit 1
fi

rm "in.txt"
/usr/bin/python3 jacktest.py > "in.txt"
# cat in.txt

# put the paths below
a=$(./a.out < in.txt)
b=$(./jack < in.txt)
if [[ $a -eq $b ]]
then
    ./test.sh $(($i + 1))
     exit $?
else
	exit 0
fi

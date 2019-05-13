#!/bin/bash

a=$1
num=`bash view.sh | tail -n+2 | grep -i -w -o $a | wc -l` 
if [ $num -eq 0 ]
then
    echo "No matching  field found"
    exit 1
else
    bash view.sh |  head -1
    bash view.sh | tail -n+2 | grep -i -w $a 
fi
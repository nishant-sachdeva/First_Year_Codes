#!/bin/bash

#so, here we'll be editing the files
num=$1
entry=$2

echo  "$num"

if [ $num -eq 1 ]
then
    echo "ERROR :: The action cannot be performed. Editing the first heading is FORBIDDEN"
else
    m=`cat songs_list | cut -d"=" -f 1 | grep -w -i -o "$num" | wc -l`
    if [ $m -eq 0 ]
    then
        echo "The specifed  id does not exist. Please give correct entry"
        echo "Here's the list for reference"
        bash view.sh
    else
        awk '!($1 ~ '$num')' songs_list > s2
        mv s2 songs_list
        bash add_entry.sh $entry 
        echo "The updated list is ..:"
        bash view.sh
    fi
fi

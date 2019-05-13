#!/bin/bash

num=$1
if [ $num -eq 1 ]
then
    echo "ERROR  :: The action cannot be performed. Deleting the first heading is FORBIDDEN"
else
    m=`cat songs_list | cut -d"=" -f 1 | grep -w -i -o "$num" | wc -l`
    if [ $m -eq 0 ]
    then
        echo "The specifed  id does not exist. Please give correct entry"
        echo "Here's the list for reference"
        bash  view.sh
    else
        awk '!($1 ~ '$num')' songs_list > s2
        mv s2 songs_list
        echo "Appropriate action  has been performed. The updated list is : "
        bash view.sh
    fi
fi

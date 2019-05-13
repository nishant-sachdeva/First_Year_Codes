#!/bin/bash

#so, the entry has been given as arguments.
# entry pattern is Song name, artist name, genre, youtube link
#i have to assign an id to the song and add that to the field accordingly 
# and be able to delete stuff accordingly

a=`cat songs_list | tail -n 1 | cut -d"=" -f 1`

song=`echo "$@" | cut -d"=" -f 1`
num=`cat songs_list | cut -d"=" -f 2 | grep -w -i -o "$song" | wc -l`
if [ $num -ne 0 ]
then
    #the song occurs before 
    echo "This seems to be duplicate entry for a song . Plis check the list for your song"
    c=`cat songs_list | grep -w -i  "$song" `
    echo "The song matches with $c"
    exit 1
else
    a=$(( a + 1 ))
    d=`date | cut -d" " -f 1`
    echo "$a = $@ = $d" >> songs_list
    echo "$a = $@ = $d"
    echo "The entry has been added to the list"
fi
  
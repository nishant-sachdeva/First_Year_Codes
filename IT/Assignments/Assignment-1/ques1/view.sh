#!/bin/bash

sort -k1 songs_list >  s2
mv s2 songs_list

end_of_file=0
while [[ $end_of_file == 0 ]]; do
    read -r line
    # the last exit status is the 
    # flag of the end of file
    end_of_file=$?
    id=`echo $line | cut -d"=" -f 1 `
    song_name=`echo $line | cut -d"=" -f 2 `
    artist_name=`echo $line | cut -d"=" -f 3 `
    genre=`echo $line | cut -d"=" -f 4 `
    link=`echo $line | cut -d"=" -f 5 `
    last_modified=`echo $line | cut -d"=" -f 6 `
    printf "%5s %30s %30s %20s %30s   %10s \n" $id $song_name $artist_name $genre $link $last_modified
done < "songs_list"
#!/bin/bash

cat movies_input | tr ":" " " | sort  -k2 -n -r | tr " " ":" > newlist

mkdir all_movies
cd all_movies
mkdir bad average good awesome
cd ..

end_of_file=0
while [[ $end_of_file == 0 ]]; do
  read -r line
  # the last exit status is the 
  # flag of the end of file
  end_of_file=$?
  b=`echo "$line" | cut -d":" -f 2`
  name=`echo "$line" | cut -d":" -f 1`
  a=${b%.*}
  if [[ "$a" -lt "5" ]]; then
   	touch all_movies/bad/$name.mp4
  elif [[ "$a" -ge "5" ]] && [[ "$a" -lt "8" ]]; then
   	touch all_movies/average/$name.mp4
  elif [[ "$a" -ge "8" ]] && [[ "$a" -lt "9" ]]; then
   	touch all_movies/good/$name.mp4
  elif [[ "$a" -gt "9" ]]; then
   	touch all_movies/awesome/$name.mp4
  fi
done < "newlist"
#!/bin/bash

num=` atq| wc -l `
echo "There are currently $num reminders"
if [ -z "$1" ]
then
	atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5
else
	atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5 | grep -w -i "$1"
fi
atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5 > reminder_list
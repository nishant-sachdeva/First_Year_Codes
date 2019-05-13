#!/bin/bash

i=$@
atrm $i
echo "Action performed as per validity of arguments"
echo "Here's a fresh copy of the list for verfications"
bash list_reminders.sh

atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5 |  tr ' ' '-' | tr '	' '|' > reminder_list

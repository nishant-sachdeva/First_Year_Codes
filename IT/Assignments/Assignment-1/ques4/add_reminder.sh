#!/bin/bash
# Nice reminders -
# take input line and break it at = supplying the args before the =
# to 'at' and the message after the = to 'notify-send'
# Examples
# remind 16:00 = Pick up boys
# remind 16:00 + 1 day = Pick up boys
# remind 17:00 2 Dec = SVBN dinner
#  | at "$1" &>> test.txt

set(){
at $1 << EOF
	notify-send  -t 500 "Reminder" "$2" 
EOF
}

ALLARGS="$@"

message=` echo "$ALLARGS" | cut -d'-' -f 1 `
time=` echo "$ALLARGS" | cut -d'-' -f 2 `


touch test.txt
echo "$ALLARGS" > test.txt
num=`cat test.txt | tr '-' '\n'  | wc -l `
rm test.txt
if [[ $num -eq 3 ]]; then
	echo "You have chosen to assign a repeating reminder. Please note, they are being assigned as separate tasks."
	echo "So, should you choose to delete them, you'll have to delete them individually"
	f=` echo "$ALLARGS" | cut -d'-' -f 3 `


	for (( i = 0; i < "$f"; i++ )); do
		set "$time + $i days" "$message"
	done

else 
	set "$time" "$message"
fi

atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5 |  tr ' ' '-' | tr '	' '|' > reminder_list


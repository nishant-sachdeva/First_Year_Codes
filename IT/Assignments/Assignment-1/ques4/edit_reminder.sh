#!/bin/bash
ALLARGS="$@"

id=` echo "$ALLARGS" | cut -d'-' -f 1 `
message=` echo "$ALLARGS" | cut -d'-' -f 3 `
time=` echo "$ALLARGS" | cut -d'-' -f 2 `

echo "The reminder is being changed. Provided, the arguments are appropriate, The new reminder is gonna be known by the details as given."

at $time << EOF
notify-send  -t 500 "Reminder" "$message"
EOF

atrm $id

atq | sort -k 6n -k 3M -k 4n -k 5 -k 7 -k 1 | cut -d" " -f 1-5 |  tr ' ' '-' | tr '	' '|' > reminder_list

#!/bin/bash


#for the file listing
tree -D -c -f | head -n -1 | cut -d'[' -f 2 | tr ']' ' '

#for the commands  listing
#compgen -A function -abck | grep -i "^[l][o]" > 2018111040.txt
printf '%s\n' ${PATH//:/\/* } |  tr '/' ' ' |awk '{print $NF}' |grep -i "^[l][o]" > 2018111040.txt
touch t.txt

while read -r line; do
    name="$line"
    var=`man "$line"  | head -4  | tail  -1 | cut -d'-' -f 2`
    echo "$name = $var" >> t.txt
done < "2018111040.txt"

mv t.txt 2018111040.txt

a=` cat 2018111040.txt | wc -l `
echo "The number of lines is $a"
a=` cat 2018111040.txt | wc -L `
echo "The length of the longest line is $a"

echo "Creating a backup...."
cp 2018111040.txt{,.bak}
echo "Backup created in a file called 2018111040.txt.bak"
a=` cat 2018111040.txt | grep -o "function" | wc -l`
echo "The word function occured $a times"
echo "Appropriately replaced"
sed 's/function/method/g' 2018111040.txt >> 2018111040.txt


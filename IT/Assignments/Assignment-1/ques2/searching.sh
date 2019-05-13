#!/bin/bash

url=$2
word=$1
num=$#
check=2
if [ "$num" -ne "$check" ]
then
	echo "The input format is incorrect"
	echo "Please check the Readme for details :)"
	echo "We will be exiting the code now"
	exit 1
fi
if curl --output /dev/null --silent --head --fail "$url"; then
  echo "$url found ...:)" 
  echo "wait for the request to be processed..."
  echo "Your patience is much appreciated :)"
  echo "Please note: The output is based on case insensitivity"
else
  echo "$url does not exist"
  echo "We will exit the code now"
  echo "Please enter a valid request next time."
  echo "Format of request can be found in the readme :)"
  exit 1
fi


touch test.txt
#curl "$url" 

#rm test.txt
a=`echo "$url" | cut -d":" -f 1`
if [[ "$a" != "https" ]]; then
  url="https://"$url
fi
echo "$url"
content=$(curl -s $url)
echo $content |awk '{gsub("<[^>]*>", "")}1' > test.txt 
echo "As a part of a pattern, the string $word occurs as follows:"
ans=` grep -o  "$word" test.txt | wc -l `
echo "$word $ans"
echo "But as word in itself, it occurs as follows:"
ans=` grep -o -w "$word" test.txt | wc -l `
echo "$word $ans"
rm test.txt
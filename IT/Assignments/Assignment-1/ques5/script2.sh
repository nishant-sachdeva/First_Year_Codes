#!/bin/bash

cat file1.csv file2.csv > target.csv
sort -k1  -n target.csv > target_file.csv
awk '{ print $1 $13 $2 $3 $4 $5 $6 $7 $8 $9 $10 $11 $12 $14 $15 }' target_file.csv > target.csv
echo "Index,Age,workclass,fnlwgt,education,education-num,marital-status,occupation,relationship,race,sex,capital-gain,capital-loss,native-country,class" > head.csv
cat head.csv target.csv > target_file.csv
cat target_file.csv | sed 's/?/2018111040/g' > target.csv
mv target.csv target_file.csv
rm head.csv 


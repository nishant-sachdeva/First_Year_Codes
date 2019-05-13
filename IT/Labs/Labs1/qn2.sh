#!/bin/bash

name=`ls`
for entry in $name 
do
  mv "$entry" "$entry.try"
done


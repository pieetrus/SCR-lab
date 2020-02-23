#!/bin/bash

ls -l | awk '{print $1, $9}' > temp1

sed 's/total//g' temp1 > temp2

cat temp2

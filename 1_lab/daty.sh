#!/bin/bash
clear

data="date +%u"

if [ "$data" == 6 ] || [ "$data" == 7 ] ;
then
    echo "Jest weekend"
else
    echo "Jest dzień roboczy"
fi

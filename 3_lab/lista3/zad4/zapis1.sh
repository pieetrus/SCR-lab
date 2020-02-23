#!/bin/bash


for x in 1 2 3 4 5 6 7 8 9 10
do
    echo "Piszę z pierwszego okna $x">>fifo
    sleep 3
done

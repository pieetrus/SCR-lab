#!/bin/bash

x=1
while : ; do
    echo "Czesc $x" > fifo
    x= [ $x+1 ]
done

      

#!/bin/bash

rozszerzenie=$1
days=$2
nazwa=$3

plik=$(find -name "*.$rozszerzenie" -atime "$days")
   
tar -cvf "$nazwa" $plik

echo Spakowano wyszukane pliki do archiwum o nazwie "$nazwa"

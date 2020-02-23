#!/bin/bash

#- maxdepth 1 tylko jeden katalog w dol idzie
#- type f file, d to katalog
# -ctime 5 -> utworzone w ostatnich 5 dniach


find . -type f -mmin -10 #zmodyfikowane w ostatnich 10 minutacch
find . -type f -mtime +20 #more than 20 days ago


find . -size +5M # pliki wieksze niz 5megabajtow| k kilo| G giga

find . -empty #puste pliki znajduje

#find . -perm 777 #permisions

# find folder -exec chown pietrus     # dla wszystkich plikow pod tym floderem wykonana jest intrukcja po exec

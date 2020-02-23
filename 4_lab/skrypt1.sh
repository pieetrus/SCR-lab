#!/bin/bash


x=1;
y=1;

trap 'echo "Chciałeś mnie zabić więc odchodzę :(((";exit' SIGALRM
trap 'echo "Jestem odporny na SIGTERM, więc wracam do roboty!"' SIGTERM
trap 'echo "Jestem odporny na SIGUSR1"' SIGUSR1
trap 'echo "Podałeś sygnał. Teraz poczekaj";
while [ $y -lt 1000 ]
do
y=$[y+1];
echo "$y"
sleep 0.1;
done' SIGUSR2

trap 'echo "Teraz już nie jestem odporny na żaden z sygnałów :("; trap - SIGUSR1;trap - SIGUSR2; trap - SIGTERM' SIGHUP

while true
do
    x=$[++x];
    sleep 0.1;
    echo $$;
    trap 'echo "Jestem odporny na SIGUSR1"' SIGUSR1
done

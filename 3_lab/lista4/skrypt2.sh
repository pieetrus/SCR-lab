#!/bin/bash

#x=1;

#while [ $x -le 60 ]
#do
#    date +%T
#    sleep 1
#    x=$[x+1]
#done

trap 'echo "Jestem odporny na SIGINT"' SIGINT
trap 'echo "Jestem odporny na SIGQUIT"' SIGQUIT
trap 'echo "Jestem odporny na SIGILL"' SIGILL
trap 'echo "Jestem odporny na SIGTRAP"' SIGTRAP
trap 'echo "Jestem odporny na SIGABRT"' SIGABRT
trap 'echo "Jestem odporny na SIGBUS"' SIGBUS
trap 'echo "Jestem odporny na SIGFPE"' SIGFPE
trap 'echo "Jestem odporny na SIGKILL"' SIGKILL
trap 'echo "Jestem odporny na SIGUSR1"' SIGUSR1
trap 'echo "Jestem odporny na SIGSEGV"' SIGSEGV
trap 'echo "Jestem odporny na SIGUSR2"' SIGUSR2
trap 'echo "Jestem odporny na SIGPIPE"' SIGPIPE
trap 'echo "Jestem odporny na SIGALRM"' SIGALRM
trap 'echo "Jestem odporny na SIGTERM"' SIGTERM

trap 'echo "Teraz już nie jestem odporny na żaden z sygnałów :("; trap - SIGINT; trap - SIGQUIT; trap - SIGILL; trap - SIGTRAP; trap - SIGABRT; trap - SIGBUS; trap - SIGFPE; trap - SIGKILL; trap - SIGUSR1; trap - SIGSEGV; trap - SIGUSR2; trap - SIGPIPE; trap - SIGALRM; trap - SIGTERM' SIGHUP

while : ; do
    echo "Moj PID to $$ ; Naciśnij ^C aby wyjść"
    sleep 5
done

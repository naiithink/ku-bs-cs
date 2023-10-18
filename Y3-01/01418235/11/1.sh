#! /usr/bin/env bash

trap "echo 'Receive SIGINT'" SIGINT
trap "echo 'Receive SIGUSR1'" SIGUSR1
trap "echo 'Receive SIGUSR2'" SIGUSR2
trap "echo 'Receive SIGALRM'" SIGALRM
trap "echo 'Receive SIGVTALRM'" SIGVTALRM

while true; do
    sleep 60
done

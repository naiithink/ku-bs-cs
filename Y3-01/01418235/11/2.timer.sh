#! /usr/bin/env bash
# $1 PID
# $2 Time to sleep in seconds

sleep $2

if kill -0 $1; then
    kill -s USR1 $1
fi

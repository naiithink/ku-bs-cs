#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

if [[ $ARGV == 0 ]]; then
    exit 1
fi

FILE_NAME=$(echo "$1" | sed -n 's/\([^\.]\)\.c/\1/p')

if [[ $(make "$FILE_NAME" 2>&1 1>/dev/null) ]]; then
    exit 1
fi

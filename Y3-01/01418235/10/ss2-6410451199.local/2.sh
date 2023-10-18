#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

if [[ $ARGV == 0 ]]; then
    exit 1
fi

FILE_NAME=$(echo "${ARGV[${1}]}" | sed -n 's/\([^\.]\)\.\([^\.]\)/\1/p')

echo $FILE_NAME

$(make "$FILE_NAME")

exit 0

if [[ ! $( make "$FILE_NAME" 2>&1 1>/dev/null ) ]]; then
    exit 1
fi

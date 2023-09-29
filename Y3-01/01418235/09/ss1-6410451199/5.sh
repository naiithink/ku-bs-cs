#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

MAX_SIZE_BYTES=$(stat -c "%s" $1)
MAX_SIZE_FILES=( $1 )

for FILE in "${ARGV[@]}"; do

    if [[ ! -a $FILE ]]; then
	exit 1
    fi
    
    FILE_SIZE=$(stat -c "%s" $FILE)

    if [[ $FILE_SIZE -gt $MAX_SIZE_BYTES ]]; then
	unset MAX_SIZE_FILES
	MAX_SIZE_FILES+=$FILE
	MAX_SIZE_BYTES=FILE_SIZE
    fi
done

echo $MAX_SIZE_FILES

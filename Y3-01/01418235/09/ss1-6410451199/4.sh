#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

NEWEST=$1
OFFSET=1

for FILE1 in "${ARGV[@]: 0:ARGC-1}"; do
    FILE2="${ARGV[OFFSET]}"
    echo $FILE1 $FILE2

    if [ $FILE2 -nt $FILE1 ]; then
	NEWEST=$FILE2
    fi

    (( OFFSET++ ))
done

echo $NEWEST

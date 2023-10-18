#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )
CC='./2.sh'

PASS=0
FAILED=0

for ARGV; do
    if [ ! -r $ARGV ]; then
	(( FAILED++ ))
    elif ! "$CC" "$ARGV"; then
	(( FAILED++ ))
    else
	(( PASS++ ))
    fi
done

printf "%d\n%d\n%d\n" $ARGC $FAILED $PASS


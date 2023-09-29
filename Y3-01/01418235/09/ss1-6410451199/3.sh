#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

MIN=$1

for I in "${ARGV[@]}"; do
	 if [[ $I < $MIN ]]; then
	     MIN=$I
	 fi
done

echo $MIN

#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

echo $ARGC

for (( I=$ARGC-1 ; $I>=0 ; $((I--)) )); do
    echo "${ARGV[$I]}"
done

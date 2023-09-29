#! /usr/bin/env bash

if (( $1 > $2 )); then
    echo "is more than $2";
elif (( $1 < $2 )); then
    echo "is less than $2";
else
    echo "is equal to $2";
fi

#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

DATE1=${1:?date1 not provided}
DATE2=${2:?date2 not provided}

UTIME1=$(date -d "$DATE1" '+%s')
UTIME2=$(date -d "$DATE2" '+%s')

DIFF=$(( UTIME2 - UTIME1 ))

echo $(( DIFF / ( 24 * 60 * 60 ) ))

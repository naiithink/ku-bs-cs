#! /usr/bin/env bash

ARGC=$#
ARGV=( $@ )

DATE1=${1:-NULL}
DATE2=${2:-NULL}

if [[ "$DATE1" == 'NULL' && "$DATE2" == 'NULL' ]]; then
    echo "You must at least provide a date!" 1>&2
    exit 1
fi

if [[ ! $(date -d "$DATE1" 2>/dev/null) ]]; then
    echo "Error occurred with argument #1, please provide a correct date!" 1>&2
    exit 1
fi

if [[ ! $(date -d "$DATE2" 2>/dev/null) ]]; then
    echo "Error occurred with argument #2, please provide a correct date!" 1>&2
    exit 1
fi

     
if [[ $DATE2 == 'NULL' ]]; then
    DATE2=$(date '+%Y-%m-%d')
fi

UTIME1=$(date -d "$DATE1" '+%s')
UTIME2=$(date -d "$DATE2" '+%s')

DIFF=$(( UTIME2 - UTIME1 ))

if [ $DIFF -lt 0 ]; then
    (( DIFF*=-1 ))
fi

echo $(( DIFF / ( 24 * 60 * 60 ) ))

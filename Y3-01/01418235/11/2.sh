#! /usr/bin/env bash

COMPILE_TIMEOUT_S=5
TIMER="${0%.*}.timer.sh"
EXT_SOURCE='c'
EXT_IN='input'
EXT_OUT='output'
EXT_TMP='tmp'

ARGC=$#
ARGV=( $@ )


# VALIDATING ARGUMENTS
if [ $ARGC -eq 0 ]; then
    exit 1
fi


# SPLITTING FILE PATH
FILE_PREFIX=$(echo "$1" | awk '{ $NF = ""; print $0 }' FS='/' OFS='/' -)
FILE_NAME=$(echo "$1" | awk '{ print $NF }' FS='/' | sed -n 's/\(.*\)\..*/\1/p')


# TESTING FILE EXISTENCE AND READABILITY
if [ ! -r "$1" ]; then
    exit 1
fi


# SETTING OUT THE COMPILATION TIMER AND HANDLING LOGIC
# timeout --preserve-status $COMPILE_TIMEOUT_S make "${FILE_PREFIX}${FILE_NAME}" &> /dev/null

trap "exit 3" SIGUSR1

sh $TIMER $$ $COMPILE_TIMEOUT_S &
TIMER_PID=$!

trap "if kill -0 $TIMER_PID; then kill -s TERM $TIMER_PID; fi" EXIT TERM INT

make "${FILE_PREFIX}${FILE_NAME}" &> /dev/null &
MAKE_PID=$!

wait $MAKE_PID

if [ $? -ne 0 ]; then
    if kill -0 $TIMER_PID; then
        kill -s TERM $TIMER_PID
    fi
    exit 2
fi

if [ $(echo "$1" | awk '{ print NF }' FS='/') -eq 1 ]; then
    CMD="./${FILE_NAME}"
else
    CMD="${FILE_PREFIX}${FILE_NAME}"
fi

$CMD < "${FILE_PREFIX}${FILE_NAME}.${EXT_IN}" > "${FILE_PREFIX}${FILE_NAME}.${EXT_TMP}"

if [ "$(cat "${FILE_PREFIX}${FILE_NAME}.${EXT_TMP}" | shasum -a 512)" = "$(cat "${FILE_PREFIX}${FILE_NAME}.${EXT_OUT}" | shasum -a 512)" ]; then
    echo 1
else
    echo 0
fi

rm "${FILE_PREFIX}${FILE_NAME}.${EXT_TMP}"

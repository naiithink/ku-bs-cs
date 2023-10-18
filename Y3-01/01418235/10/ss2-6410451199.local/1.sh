#! /usr/bin/env bash

# 1.1
# 
# passwd
# login_name[:encrypted_password]:uid:gid:username/comment:home[:shell]
#
# Prints login name and username/comment according to the provided user ID


# 1.2
#
# for id
#
# for id in $@


# 1.3
#
# Both Ubuntu and Debian, the sukreep server, has the default shell set to Bash.
# Bash separates each command line argument with one or more white space characters.
# 
# Therefor, Bash would interpret:
#
# `$ script-name Mailing List Manager'
#
# as
#
# $0: script-name
# $1: Mailing
# $2: List
# $3: Manager
#
#
# Since "Mailing List Manager" is enclosed within quotes, Bash would interpret it as a single string
# 
# `$ script-name "Mailing List Manager"'
#
# as
#
# $0: script-name
# $1: "Mailing List Manager"

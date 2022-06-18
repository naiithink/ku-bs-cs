#!/usr/bin/env bash

SHELL='zsh'
PROJ='private'
USER_NAME='Potsawat Thinkanwatthana'
USER_EMAIL='potsawattkw@outlook.com'

echo "export SHELL=$SHELL" >> $HOME/.${SHELL}rc
echo 'export GPG_TTY=$(tty)' >> $HOME/.${SHELL}rc
git config --global oh-my-zsh.hide-info 1
git config --global core.autocrlf input
git config --global user.name $USER_NAME
git config --global user.email $USER_EMAIL
git config --global commit.template .gitmessage
git remote add gh git@github.com:${USER_NAME}/${PROJ}.git
git remote add all git@gitlab.com:${USER_NAME}/${PROJ}.git
git remote set-url --push --add all git@gitlab.com:${USER_NAME}/${PROJ}.git
git remote set-url --push --add all git@github.com:${USER_NAME}/${PROJ}.git

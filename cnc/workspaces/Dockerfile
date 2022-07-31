FROM    ubuntu:22.04

ARG     USR_NAME=foo

RUN     useradd $USR_NAME \
        && usermod --groups root $USR_NAME

USER    $USR_NAME

ARG     DEBIAN_FRONTEND=noninteractive
ARG     APTGET_OPTS="-y --no-install-recommends"

RUN     apt-get update && apt-get upgrade -y

RUN     apt-get install ${APTGET_OPTS} ca-certificates gnupg2 \
        && apt-get install ${APTGET_OPTS} build-essential gdb git emacs valgrind vim \
        && apt-get install ${APTGET_OPTS} python3 python3-dev python3-pip python3-venv \
        && apt-get install ${APTGET_OPTS} ruby-full \
        && apt-get install ${APTGET_OPTS} nodejs \
        && apt-get install ${APTGET_OPTS} emscripten

RUN     apt-get install ${APTGET_OPTS} latexmk texlive texlive-xetex \
        && apt-get install ${APTGET_OPTS} ghostscript pandoc

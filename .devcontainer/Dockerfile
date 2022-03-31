# [Choice] Ubuntu version (use hirsute or bionic on local arm64/Apple Silicon): hirsute, focal, bionic
ARG     VARIANT="hirsute"
FROM    mcr.microsoft.com/vscode/devcontainers/base:${VARIANT}

# [Optional] Uncomment this section to install additional OS packages.
RUN     apt-get update && export DEBIAN_FRONTEND=noninteractive \
        && apt-get -y install --no-install-recommends automake build-essential gnupg2 libtool-bin libncurses-dev libc6-dbg libxml2-dev

# Some More Packages
RUN     apt-get update && apt-get -y upgrade \
        && apt-get install -y --no-install-recommends clang-format clang-tidy clang-tools clang clangd libc++-dev libc++1 libc++abi-dev libc++abi1 libclang-dev libclang1 liblldb-dev libllvm-ocaml-dev libomp-dev libomp5 lld lldb llvm-dev llvm-runtime llvm python3-clang \
        && apt-get install -y --no-install-recommends python3 python3-dev python3-pip python3-venv \
        && apt-get install -y --no-install-recommends default-jdk \
        && apt-get install -y --no-install-recommends nodejs npm \
        && apt-get install -y --no-install-recommends valgrind \
        # Swift
        # && apt-get install binutils libc6-dev libcurl4 libedit2 libgcc-9-dev libpython2.7 libsqlite3-0 libstdc++-9-dev libz3-dev pkg-config tzdata uuid-dev zlib1g-dev
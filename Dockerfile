FROM amd64/ubuntu:20.04

RUN apt-get update && apt install -y tzdata

# 環境変数の設定
ENV TZ=Asia/Tokyo
ENV DEBIAN_FRONTEND=noninteractive
ENV PATH=$PATH:/usr/local/go/bin
ENV GOPATH=/workspace/golang

RUN apt-get install -y git curl wget build-essential apt-utils software-properties-common && \
    # C/C++
    # add-apt-repository ppa:ubuntu-toolchain-r/test && apt-get update && \
    apt-get install -y gcc-10 gcc-10-base gcc-10-doc g++-10 libstdc++-10-dev libstdc++-10-doc && \
    # Golang
    # add-apt-repository ppa:longsleep/golang-backports && apt-get update && apt -y install golang-go &&\
    wget https://go.dev/dl/go1.17.3.linux-amd64.tar.gz && tar -xvf go1.17.3.linux-amd64.tar.gz && \
    mv go /usr/local && rm go1.17.3.linux-amd64.tar.gz && \
    # Python
    apt install -y python3-dev python3-pip && \
    # Rust
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh && source ~/.profile && \
    # TypeScript
    apt install -y nodejs npm

# 作業ディレクトリの設定
WORKDIR /workspace
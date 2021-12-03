FROM amd64/ubuntu:20.04

RUN apt-get update && apt install -y tzdata

# 環境変数の設定
ENV TZ=Asia/Tokyo
ENV DEBIAN_FRONTEND=noninteractive
ENV PATH=$PATH:/usr/local/go/bin
ENV GOPATH=/workspace/golang

# RUN echo 'nameserver 8.8.8.8' >> /etc/resolv.conf
RUN apt-get install -y git curl wget apt-utils build-essential software-properties-common libreadline-gplv2-dev \
    libncursesw5-dev libssl-dev libsqlite3-dev tk-dev libgdbm-dev libc6-dev libbz2-dev libffi-dev zlib1g-dev &&\
    # C/C++
    apt-get install -y gcc-10 gcc-10-base gcc-10-doc g++-10 libstdc++-10-dev libstdc++-10-doc && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10 && \
    # Golang
    wget https://go.dev/dl/go1.17.3.linux-amd64.tar.gz && tar -xvf go1.17.3.linux-amd64.tar.gz && \
    mv go /usr/local && rm go1.17.3.linux-amd64.tar.gz && \
    # Python
    add-apt-repository ppa:deadsnakes/ppa -y && apt install -y python3.10 python3-pip && \
    update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.10 20 && \
    update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 10 && \
    # Rust
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- --default-toolchain none -y &&\
    . $HOME/.cargo/env && rustup update stable && \
    # TypeScript
    apt install -y nodejs npm && npm install -g n && n stable && apt purge -y nodejs npm
    # TypeScript (M1 Mac)
    # apt install -y nodejs npm && npm install -g n && n v14.18.1 && apt purge -y nodejs npm

# 作業ディレクトリの設定
WORKDIR /workspace

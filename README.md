# プログラミングの勉強用リポジトリ
各種プログラミング言語の入門書を読みながら文法や作法を学びます．
Docker で動かしているので，どんな環境でもできる (はず...) です．

## C/C++
「[Sams Teach Yourself C++ in One Hour a Day, 9th edition](https://learning.oreilly.com/library/view/sams-teach-yourself/9780137334674/)」 (著：Siddhartha Rao, February 2022)

## Golang
「[Learning Go](https://www.oreilly.com/library/view/learning-go/9781492077206/)」 (著：John Bodner, March 2021)

## Python
「[Fluent Python, 2nd Edition](https://learning.oreilly.com/library/view/fluent-python-2nd/9781492056348/)」 (著：Luciano Ramalho, April 2022)

## Rust
「[Programming Rust, 2nd Edition](https://learning.oreilly.com/library/view/programming-rust-2nd/9781492052586/)」 (著：Jim Blandy, Jason Orendorff, Leonora F.S. Tindall, June 2021)

## TypeScript
「[Programming TypeScript](https://learning.oreilly.com/library/view/programming-typescript/9781492037644/)」 (著：Boris Cherny, May 2019)

## 環境の立ち上げ
```bash
# イメージの作成
$ docker-compose build

# コンテナの起動
$ docker-compose run --rm programming_languages_env bash

# Ctrl + D で終了
```

## M1 MacBook Air での実行
Node.js の最新安定版が対応していないので，以下のコメントアウトを外す．

```Dockerfile
# TypeScript (M1 Mac)
apt install -y nodejs npm && npm install -g n && n v14.18.1 && apt purge -y nodejs npm
```
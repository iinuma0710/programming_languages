# 2-1. rustup と Cargo
Rust のインストールは [rustup](https://rustup.rs) で行います．
インストールやアップデートはリンク先のページを参照してください．
インストールが完了すると，次の3つのコマンドが使えるようになります．

- ```cargo```  
  コンパイルやパッケージの管理を行う汎用マネージャです．
  新規プロジェクトの開始やプログラムのビルドと実行，外部ライブラリの管理を行います．
- ```rustc```  
  コンパイルコマンドですが，通常は ```cargo``` コマンドを使います．
  ただし，直接実行する際には便利なコマンドです．
- ```rustdoc```  
  指定された形式でコード中にコメントを付けると，HTML に整形してドキュメントを出力します．
  ```rustc``` 同様 ```cargo``` で代用できます．

```cargo``` コマンドで新しいパッケージを作成できます．
この時，一緒にメタデータの生成なども行われます．

```bash
$ cargo new hello
     Created binary (application) `hello` package
```

この時，```Cargo.toml``` というパッケージのメタデータが格納されたファイルが生成されます．

```toml
[package]
name = "hello"
version = "0.1.0"
edition = "2021"

# See more keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

[dependencies]
```

このファイルに依存するライブラリを書いておけば，ダウンロードやビルド，アップデートを自動的にやってくれます．
```Cargo.toml``` ファイルについて，詳しくは第8章で扱います．  
```src``` ディレクトリの中には ```main.rs``` ファイルが生成されており，次のような内容が記述されています．

```rust
fn main() {
    println!("Hello, world!");
}
```

パッケージのディレクトリで ```cargo run``` と入力すると，プログラムが実行されます．

```bash
$ cargo run
   Compiling hello v0.1.0 (/workspace/rust/ch02/hello)
    Finished dev [unoptimized + debuginfo] target(s) in 0.49s
     Running `target/debug/hello`
Hello, world!
```

最初に ```rustc``` でコンパイルが実行され，実行可能ファイルが実行されます．
実行ファイルは ```target``` サブディレクトリ内に置かれています．

```bash
$ ls -l ./target/debug/
total 3604
drwxr-xr-x 2 root root    4096 Dec  3 21:59 build
drwxr-xr-x 2 root root    4096 Dec  3 21:59 deps
drwxr-xr-x 2 root root    4096 Dec  3 21:59 examples
-rwxr-xr-x 2 root root 3669160 Dec  3 21:59 hello
-rw-r--r-- 1 root root      86 Dec  3 21:59 hello.d
drwxr-xr-x 3 root root    4096 Dec  3 21:59 incremental
$ ./target/debug/hello
Hello, world!
```

```cargo clean``` で生成されたファイルを削除できます．

```bash
$ cargo clean
$ ./target/debug/hello
bash: ./target/debug/hello: No such file or directory
```
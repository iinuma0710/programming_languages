# 2-7. ファイルシステムとコマンドラインツール
Rust はモダンで安全で高速なシステムプログラミング言語として，従来のツールの機能を置き換えたり拡張するようなコマンドラインインターフェイスを構築できるツールボックスを提供しています．
例えば，```bat``` コマンドはページングツールをビルトインでサポートし，```cat``` コマンドの代わりとして機能します．
また，```hyperfine``` はコマンドやパイプラインで実行可能なものならなんでも，自動的にベンチマークを取ることができます．

Rust を使えば人間工学に基づいたコマンドラインアプリケーションの世界に簡単に足を踏み入れることができます．
本節では，カラフルな出力と分かりやすいエラーメッセージを備えた独自の検索・置換ツールを作成します．

まずは，新しいプロジェクト ```quickreplace``` を作成します．
今回は，ターミナルの出力に色をつける ```text-colorizer``` と，検索と置換を実行する ```regex``` という2つのクレートを使用します．
最初に，```Cargo.toml``` に書き込んでおきましょう．

```toml
[package]
name = "quickreplace"
version = "0.1.0"
edition = "2021"

# See more keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

[dependencies]
text-colorizer = "1"
regex = "1"
```

Rust ではバージョンが ```1.0``` に到達すると，セマンティックバージョニング (semantic versioning) という規則に従います．
このルールでは，メジャーバージョンが変わらなければ，常に後方互換性が担保されています．
すなわち，バージョン ```1.2``` でテストして動作したコードは，バージョン ```1.3``` や ```1.4``` でも動作することが保証されています．
一方，メジャーバージョンが ```2.0``` のように変更になった場合には， 互換性のない変更が適用されます．
```"1"``` のようなバージョンの指定をしておくと，そのメジャーバージョンの中で最新のものを自動的に選択するようになっています．

## コマンドラインインターフェイス
今回作成するコマンドラインツールは，

- 検索する文字列，または正規表現
- 置換する文字列，または正規表現
- 入力ファイル
- 出力ファイル

の4つを引数として受け取ります．
初めに，これらを含む構造体を定義します．

```rust
#[derive(Debug)]
struct Arguments {
    target: String,
    replacement: String,
    filename: String,
    output: String,
}
```

```#[derive(Debug)]``` 属性を付与しておくと， ```println!``` で ```{:?}``` によるフォーマットが可能になります．

引数の数が間違えていた場合には，プログラムの使い方を表示してやります．
これは，```print_usage``` 関数を呼び出すことで実現します．

```rust
use text_colorizer::*;

fn print_usage() {
    eprintln!("{} - change occurrences of one string into another", "quickreplace".green());
    eprintln!("Usage: quickreplace <target> <replacement> <INPUT> <OUTPUT>");
}
```

```.green()``` を文字列リテラルの後ろにつけるだけで，適当な ANSI のエスケープコードでラップして，ターミナル状で緑に表示されるようにしてくれます．

続いて，引数を処理する関数を定義します．

```rust
use std::env;

fn parse_args() -> Arguments {
    let args : Vec<String> = env::args().skip(1).collect();

    if args.len() != 4 {
        print_usage();
        eprintln!("{} wrong number of arguments: expected 4, got {}.", "Error:".red().bold(), args.len());
        std::process::exit(1);
    }

    Arguments {
        target: args[0].clone(),
        replacement: args[1].clone(),
        filename: args[2].clone(),
        output: args[3].clone(),
    }
}
```

コマンドライン引数の最初の要素は実行されるプログラム名なので，```.skip(1)``` で飛ばします．
その後，```collect()``` メソッドで引数を ```Vec``` 型に整形し，引数の数が正しいかをチェックしています．
もし引数の数が正しくなければメッセージを表示してプログラムを終了します．
```bold()``` メソッドは太字で表示してくれます．
最後に，引数の数が正しければ，```Arguments``` 構造体に詰めて値を返します．

それでは，この関数をメイン関数で呼び出すようにしておきましょう．

```rust
fn main() {
    let args = parse_args();
    println!("{:?}", args);
}
```

それでは一度プログラムを走らせて見ましょう．

```bash
$ cargo run
Compiling quickreplace v0.1.0 (/Users/iinuma/programming_languages/rust/ch02/quickreplace)
quickreplace - change occurrences of one string into another
Usage: quickreplace <target> <replacement> <INPUT> <OUTPUT>
Error: wrong number of arguments: expected 4, got 0.

$ cargo run "find" "replace" file output
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/quickreplace find replace file output`
Arguments { target: "find", replacement: "replace", filename: "file", output: "output" }
```

## ファイルの読み書き
続いて，ファイルからデータを読み込んで処理してからファイルに書き戻す方法を見ていきましょう．
Rust には強力な入出力ツールが用意されていて，```std::fs``` から簡単にファイルデータにアクセスする ```read_to_string``` や ```write``` 関数を使えるようになっています．

```std::fs::read_to_string``` は ```Result<String, std::io::Error``` 型の値を返します．
つまり，読み込みに成功すれば文字列を返し，失敗すれば標準ライブラリの入出力エラーを返します．
同様に，```std::fs::write``` は ```Result<(), std::io::Error>``` を返します．
これは，成功時には何も返さず，失敗時にのみエラーの詳細を返すことを表しています．

```rust
use std::fs;

fn main() {
    let args = parse_args();
    
    let data = match fs::read_to_string(&args.filename) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("{} failed to read from file '{}': {:?}", "Error:".red().bold(), args.filename, e);
            std::process::exit(1);
        }
    };

    match fs::write(&args.output, &data) {
        Ok(_) => {},
        Err(e)=> {
            eprintln!("{} failed to write to file '{}': {:?}", "Error:".red().bold(), args.output, e);
            std::process::exit(1);
        }
    };
}
```

ここでは，```parse_args``` 関数で得られた結果から ```filename``` と ```output``` を取り出して  ```read_to_string``` と ```write``` に渡しています．
それでは，メイン関数を書き換えて実行してみましょう．

```bash
$ cargo run "find" "replace" Cargo.toml Copy.toml
  Compiling quickreplace v0.1.0 (/Users/iinuma/programming_languages/rust/ch02/quickreplace)
    Finished dev [unoptimized + debuginfo] target(s) in 0.37s
     Running `target/debug/quickreplace find replace Cargo.toml Copy.toml`
```

このプログラムでは，単に ```Cargo.toml``` から内容を読み出して，```Copy.toml``` にそのまま書き出しているだけなので，内容は変更されていません．

## 探索と置換
最後に，正規表現を使って文言の探索と置換を実現する機能を実装します．
ここでは ```regex``` クレートを利用します．
```Regex``` と呼ばれる構造体を使って，```replace_all``` メソッドを呼び出すことで，正規表現に一致する文字列を全て見つけ出し，それを指定された文字列に置き換えていきます．

```rust
use regex::Regex;

fn replace(target: &str, replacement: &str, text: &str) -> Result<String, regex::Error>
{
    let regex = Regex::new(target)?;
    Ok(regex.replace_all(text, replacement).to_string())
}
```

このように，```replace``` 関数では ```Result``` で結果を返しますが，エラーの型は ```regex``` クレートで提供されているものを利用します．
```Regex::new``` はユーザの指定した正規表現をコンパイルして，不正な文字列があった場合にはエラーとなります．
正しくコンパイルされれば，後は ```replace_all``` で文字列を置き換えてやります．  
```replace_all``` メソッドは，一致する文字列があれば置換された文字列を ```String``` 型で返しますが，一致箇所がない場合には余計なメモリの消費や文字列のコピーを抑えるため，文字列のポインタを返します．
しかし，今回は文字列を返り値として受け取りたいので，```to_string``` メソッドで ```String``` 型に変換しています．

それでは，メイン関数を書き換えていきましょう．

```rust
fn main() {
    let args = parse_args();
    
    let data = match fs::read_to_string(&args.filename) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("{} failed to read from file '{}': {:?}", "Error:".red().bold(), args.filename, e);
            std::process::exit(1);
        }
    };

    let replaced_data = match replace(&args.target, &args.replacement, &data) {
        Ok(v) => v,
        Err(e) => {
            eprintln!("{} failed to replace text: {:?}", "Error:".red().bold(), e);
            std::process::exit(1);
        }
    }

    match fs::write(&args.output, &replaced_data) {
        Ok(v) => v,
        Err(e)=> {
            eprintln!("{} failed to write to file '{}': {:?}", "Error:".red().bold(), args.output, e);
            std::process::exit(1);
        }
    };
}
```

テスト用のファイルを用意して実行してみます．

```bash
$ echo "Hello, world" > test.txt
$ cargo run "world" "Rust" test.txt test-modified.txt
   Compiling quickreplace v0.1.0 (/Users/iinuma/programming_languages/rust/ch02/quickreplace)
    Finished dev [unoptimized + debuginfo] target(s) in 0.36s
     Running `target/debug/quickreplace world Rust test.txt test-modified.txt`
$ cat test-modified.txt
Hello, Rust
```

もちろん，エラー処理もきちんとできます．

```bash
$ cargo run "[[a-z]" "0" test.txt test-modified.txt
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/quickreplace '[[a-z]' 0 test.txt test-modified.txt`
Error: failed to replace text: Syntax(
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
regex parse error:
    [[a-z]
    ^
error: unclosed character class
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
)
```

ここでは紹介しきれていない基本事項も多々ありますが，ファイルの読み書きやエラーの収集と表示，ターミナル出力の色付けなど説明してきました．
以降の章では，様々な発展的手法を紹介しますが，まずは基礎としてデータ型について見ていきます．

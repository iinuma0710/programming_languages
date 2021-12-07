# 2-4. コマンドライン引数の扱い方
コマンドラインから指定された2つの引数について，先ほど定義した ```gcd``` 関数を使って最大公約数を求めるメイン関数を以下に示します．

```rust
use std::str::FromStr;
use std::env;

fn main() {
    let mut numbers = Vec::new();

    for arg in env::args().skip(1) {
        numbers.push(u64::from_str(&arg).expect("error parsing argument"));
    }

    if numbers.len() == 0 {
        eprintln!("Usage: gcd NUMBER ...");
        std::process::exit(1);
    }

    let mut d = numbers[0];
    for m in &numbers[1..] {
        d = gcd(d, *m);
    }

    println!("The greatest common divisor of {:?} is {}", numbers, d);
}
```

1つずつ細かく見ていきましょう．  

```rust
use std::str::FromStr;
use std::env;
```

```use``` 宣言によって標準ライブラリの trait ```FromStr``` をスコープに読み込んでいます．
trait は型を定義できるメソッドの集合です．
```u64``` 型で実装された ```FromStr``` は ```u64::from_str``` を呼び出すことで，コマンドライン引数をパースします．
また，2つ目の ```use``` 宣言で読み込んでいる ```std::env``` モジュールには，```args``` 関数などが含まれます．
trait について，詳細は第11章で扱います．

続いて，メイン関数を見てみましょう．
メイン関数は返り値がないので ```->``` を省略できます．

```rust
let mut numbers = Vec::new();
```

初めに，ミュータブルなローカル変数 ```numbers``` を空のベクトルで初期化しています．
Rust の ```Vec``` は，C++ の ```std::vector``` や Python のリスト，JavaScript の配列と似た，可変長のベクトル型です．
ここで宣言された ```numbers``` は ```Vec<u64>``` 型ですが，```numbers``` に格納される値や渡される関数 (```gcd```) のパラメータが ```u64``` しか取らないことから，Rust が自動的に推論してくれます．
そのため，```<u64>``` は省略されています．

```rust
for arg in env::args().skip(1) {
```

```for``` ループで変数 ```arg``` を定義してループ内の処理に渡しています．
```env::args``` 関数はイテレータ (iterator) を返す関数です．
イテレータは第15章で扱いますが，Rust では様々な場面でイテレータを使うことになります．
また，イテレータには様々なメソッドが用意されています．
例えば，コマンドライン引数の先頭の要素は，必ず実行されるプログラム名となっているので，```skip``` メソッドを使って先頭要素をスキップできます．

```rust
numbers.push(u64::from_str(&arg).expect("error parsing argument"));
```

```u64::from_str``` 関数はコマンドライン引数を，文字列から符号なし64ビット整数に変換しようとします．
ただし，```u64``` 型を直接返すのではなく，```Result``` 値を返します．
```Result``` はパースが成功したか否かによって，以下の値のいずれかを返します．

- ```Ok(v)``` : パースが成功したことを表し，```v``` は得られた値が格納されている
- ```Err(e)``` : パースが失敗したことを表し，```e``` はエラーの理由が格納されている

この例に限らず入出力や OS とのやり取りが必要な処理については ```Result``` が返却されます．
モダンなプログラミング言語と異なり，Rust は例外を持ちません．
全ての失敗は ```Result``` かパニックを使って扱います．
これについては第7章で扱います．
```except``` メソッドはパースが失敗した場合，```e``` に含まれるメッセージを表示して直ちにプログラムを終了します．
一方，成功していれば単に ```v``` の値を返すだけです．

```rust
if numbers.len() == 0 {
    eprintln!("Usage: gcd NUMBER ...");
    std::process::exit(1);
}
```

少なくとも1つは数値が入っていないと最大公約数は求められないので，ここでチェックしています．
```eprintln!``` マクロは指定したメッセージを標準エラー出力に表示します．

```rust
let mut d = numbers[0];
for m in &numbers[1..] {
    d = gcd(d, *m);
}
```

```d``` をミュータブルに設定しておいて，最大公約数を更新しながら，入力されたすべての値の最大公約数を求めています．
ここでは，ベクトル型を使っていますが，メモリサイズは不定でとても大きい可能性があります．
このような値を扱うとき，Rust ではなるべくメモリの消費を抑えながら，不要になった場合にはすぐに解放するように警告しています．
そのため，繰り返し処理をするときには，ベクトルの「所有権 (ownership)」は ```numbers``` にあるべきで，ループ処理のために要素を間借りしているだけであることを Rust に伝えたいわけです．
```&numbers[1..]``` の ```&``` 演算子は，ベクトルの2番目以降の要素の「参照 (reference)」を借りてきていることを表しています．
```for``` ループでは順番に ```m``` に参照の値を格納していきます．
```*m``` の ```*``` は ```m``` の指す値を取得することを表しています．
最後，```main``` 関数の終了時に ```numbers``` は自動的に解放されます．  
所有権と参照は Rust のメモリ管理と安全な並列処理にとって非常に重要です．
これについては第4章と第5章で詳しく扱います．

```rust
println!("The greatest common divisor of {:?} is {}", numbers, d);
```

最後に結果を表示しています．
```println!``` は ```{...}``` という形式を含むテンプレート文字列を取って，標準出力に内容を表示するマクロです．

C や C++ では，プログラムが正常に終了した場合には，```main``` 関数の最後でゼロを返し，それ以外の場合にはゼロではない終了状態を返します．
一方，Rust では ```main``` に戻ってきたときには，プログラムは正常に終了しています．
唯一，明示的に ```expect``` や ```std::process::exit``` が呼ばれたときにだけエラーステータスコードを出力して終了します．

それでは，プログラムを実行してみましょう．

```bash
$ cargo run 42 56
   Compiling gcd v0.1.0 (/workspace/rust/ch02/gcd)
    Finished dev [unoptimized + debuginfo] target(s) in 0.63s
     Running `target/debug/gcd 42 56`
The greatest common divisor of [42, 56] is 14
$ cargo run 799459 28823 27347
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/gcd 799459 28823 27347`
The greatest common divisor of [799459, 28823, 27347] is 41
$ cargo run 83
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/gcd 83`
The greatest common divisor of [83] is 83
$ cargo run
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/gcd`
Usage: gcd NUMBER ...
```

より詳しい導入は Rust の公式ページを見てください．
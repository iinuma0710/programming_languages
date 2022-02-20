# 5-1. 値への参照
例として，ルネサンス期の殺人芸術家と，その作品の一覧表を作ってみましょう．
Rust の標準ライブラリにはハッシュテーブル型があるので，次のように型を定義できます．

```rust
use std::collections::HashMap;

type Table = HashMap<String, Vec<String>>;
```

言い換えると，これは ```String``` の値を　```Vec<String>``` の値にマッピングするハッシュテーブルです．
ここでは，芸術家の名前を取って，その作品名のリストを返します．
```for``` ループによって ```HashMap``` 全体をイテレーションで舐めることができるので，```Table``` を表示する関数を次のように書けます．

```rust
fn show(table: Table) {
    for (artist, works) in table {
        println!("works by {}:", artist);
        for work in works {
            println!("  {}", work);
        }
    }
}
```

テーブルの構築と表示は簡単なものを使います．

```rust
fn main() {
    let mut table = Table::new();
    table.insert("Gesualdo".to_string(),
                 vec!["many madrigals".to_string(),
                      "Tenebrae Responsoria".to_string()]);
    table.insert("Caravaggio".to_string(),
                 vec!["The Musicians".to_string(),
                      "The Calling of St. Matthew".to_string()]);
    table.insert("Cellini".to_string(),
                 vec!["Perseus with the head of Medusa".to_string(),
                      "a salt cellar".to_string()]);

    show(table);
}
```

問題なく実行できます．

```bash
$ cargo run
   Compiling fragments v0.1.0 (/Users/iinuma/programming_languages/rust/ch05/fragments)
    Finished dev [unoptimized + debuginfo] target(s) in 0.52s
     Running `target/debug/fragments`
works by Caravaggio:
  The Musicians
  The Calling of St. Matthew
works by Gesualdo:
  many madrigals
  Tenebrae Responsoria
works by Cellini:
  Perseus with the head of Medusa
  a salt cellar
```

しかし，移動について扱った前章を読んでいると，```show``` の定義にはいくつか疑問が生じます．
特に，```HashMap``` が ```Copy``` 型ではないのです．
これは，動的に確保されるテーブルを所有しているため，```Copy``` 型にはなり得ないのです．
そのため，プログラムが ```show(table)``` を呼び出すと，構造体全体が関数に移動し，変数 ```table``` は初期化されていない状態になります．
(中身のイテレーションは順序を考慮しないので，定義したのとは違う順番で出力されても心配しないでください．)
もし，```show``` 関数を呼び出した後に ```table``` を使おうとすると，問題が発生します．

```rust
show(table);
assert_eq!(table["Gesualdo"][0], "many madrigals");
```

```tabel``` はもう使えないと怒られます．

```bash
error[E0382]: borrow of moved value: `table`
  --> src/main.rs:18:16
   |
6  |     let mut table = Table::new();
   |         --------- move occurs because `table` has type `HashMap<String, Vec<String>>`, which does not implement the `Copy` trait
...
17 |     show(table);
   |          ----- value moved here
18 |     assert_eq!(table["Gesualdo"][0], "many madrigals");
   |                ^^^^^ value borrowed here after mov
```

実は，```show``` の定義を見てみると，外側の ```for``` ループがハッシュテーブルの所有権を取得し，それを全て消費しています．
また，内側の ```for``` ループでは同じ処理を，各ベクトルに適用しています．
移動の意味を考えると，構造体を表示しようとしたことで，構造体全体が完全に破壊されます．

参照を使うことで，これを正しく扱えるようになります．
参照によって，所有権に影響を与えることなく，値にアクセスできます．
参照には2種類あります．

- 共有参照 (shared reference) は，参照先の読み込みは可能ですが，変更はできません．
  しかし，特定の値への共有参照は幾つでも作成できます．
  ```&e``` という表現は，```e``` の値への共有参照を表します．
  ```e``` が ```T``` という型を持っていれば，```&e``` は ```&T``` ("ref T") 型になります．
  共有参照は ```Copy``` 型です．
- ミュータブル参照 (mutable reference) であれば，値の読み込みも修正も両方可能となります．
  ただし，その値に対する他のいかなる種類の参照も，同時にアクティブにしてはいけません．
  ```&mut e``` という表現は，```e``` の値へのミュータブル参照を表します．
  その型は ```&mut T``` ("ref mute T") になります．
  ミュータブル参照は ```Copy``` 型ではありません．

共有参照とミュータブル参照の区別は，コンパイル時に課される複数リーダ単一ライタ (multiple reader or single writer) のルールに照らして考えられます．
実は，このルールは参照に限って適用されるものではありません．
借用した値の所有者についても適用されます．
値への共有参照が存在している間は，その所有者でも内容を変更できず，値はロックされます．
```show``` 関数が実行中の間には ```table``` を変更できません．
同様に，値へのミュータブル参照が存在する場合には，値へのアクセスが排他的になります．
ミュータブル参照が消えるまで，所有者を使うこともできません． 
このように，共有参照とミュータブル参照を完全に分けて扱うことは，メモリの安全性にとって非常に重要です．

```show``` 関数は，テーブルの内容を読むだけで修正する必要はありません．
従って，次のように，テーブルの共有参照を渡すこともできるはずです．

```rust
show(&table);
```

参照は所有権を持たないポインタなので，```table``` 変数は構造体全体の所有者のままで，```show``` 関数はそれを間借りしているだけになります．
当然，```show``` 関数の定義も上記に合わせて変更する必要がありますが，その違いをよく見てみましょう．

```rust
fn show(table: &Table) {
    for (artist, works) in table {
        println!("works by {}:", artist);
        for work in works {
            println!("  {}", work);
        }
    }
}
```

```show``` 関数のパラメータ ```table``` の型が，```Table``` から ```&Table``` に変更されています．
テーブルの値を渡す (それに伴い所有権も関数に移る) 代わりに，共有参照を渡しています．
字面の上では，変更はこれだけです．
しかし，関数本体はどのように振る舞うのでしょうか？

元の外側の ```for``` ループは ```HashMap``` の所有権を受け取って消費してしまう一方，新しい方の関数では，```HashMap``` への参照を受け取ります．
```HashMap``` への共有参照の繰り返し処理は，各エントリのキーと値への共有参照を生成します．
つまり，```artist``` は ```String``` から ```&String``` へ，```works``` は ```Vec<String>``` から ```&Vec<String>``` に変わります．

内側のループも同じように変更されます．
ベクトルへの参照のイテレーションは，その要素に対する共有参照を返すように定義されていますので，```work``` は ```&String``` となります．
この関数では所有権の変更は起こらず，所有権のない参照をやりとりしているだけです．

ここで，各芸術家の作品をアルファベット順に並べ替える関数を書きたい場合には，共有参照では内容を変更できないので不十分です．
代わりに，ソートを行う関数はテーブルへのミュータブル参照を取る必要があります．

```rust
fn sort_works(table: &mut Table) {
    for (_artist, works) in table {
        works.sort();
    }
}
```

そして，テーブルは次のように渡します．

```rust
sort_works(&mut table)
```

このミュータブルな借用によって，ベクトルの ```sort``` メソッドに必要な，構造体の読み込みと修正を ```sort_works``` でできるようになります．

値の所有権が関数に移動するような方法で関数に値を渡すとき，これを「値渡し」と呼びます．
代わりに，値への参照を関数に渡すような方法は，これを「参照渡し」と呼びます．
例えば，```show``` 関数を値ではなく参照によってテーブルを受け取るように変更しています．
多くの言語でこの区別をしていますが，所有権がどう影響を受けるのか変わってくるので，Rust では特に重要です．

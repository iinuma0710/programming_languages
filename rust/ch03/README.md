# 第3章 基本的な型
```
There are many, many types of books in the world, which makes good sense, because there are many, many types of people, and everybody wants to read something different.

世の中には実に様々なタイプの本がある．様々な人々がいて皆違うものを読みたいのだから，それは理にかなっている．

- Lemony Snicket
```

Rust という言語は，かなりの部分を型を中心として設計されています．
簡潔さとコストのバランスを保ちつつ，状況に合わせて最適な表現を選択することで高性能なコードを作成できます．
また，メモリとスレッドの安全性は，Rust の型システムの安全性とジェネリック型やとレイトの柔軟性によってよって保証されています．

本章では値を表現する Rust の基本的な方について見ていきます．
これらソースレベルの型は，コストと性能を予測可能なそれぞれに対応するマシンレベルの具体的な型を持っています．
必ずしも厳密に要求に合った方が存在するとは限りませんが，確実に改善する場合にのみ要求を逸脱するよう配慮しています．

Python や JavaScript のような動的型付け言語と比較すると，Rust は前もってしっかりと計画を立てる必要があります．
関数の引数と返り値の型や構造体フィールド，その他いくつかのコンストラクタを明示しなければなりません．
しかし，次のような Rust の特徴によって，その負担を軽減してくれます．

- ある型を明記しておけば，その他大部分の型を型推論によって解決してくれます．実際には，ある変数や式に対応する型が一つしかないことがよくあります．このような場合，Rust は型を省略することができます．例えば，次のように，関数内の全ての方を明記することもできます．

```rust
fn build_vector() -> Vec<i16> {
    let mut v: Vec<i16> = Vec::<i16>::new();
    v.push(10i16);
    v.push(20i16);
    v
}
```

しかし，これでは煩雑でくどい書き方になってしまいます．
関数の返り値の型が与えられた時点で，```v``` が16ビット符号付き整数のベクトル ```Vec<i16>``` であることは明らかで，それ以外の型では機能しません．
また，そのベクトルの要素も ```i16``` でなければいけません．
従って，Rust の型推論を使えば次のように書けるのです．

```rust
fn build_vector() -> Vec<i16> {
    let mut v = Vec::new();
    v.push(10);
    v.push(20);
    v
}
```

これらのコードは完全に等価で，全く同じ機械語のコードが生成されます．
型推論を使えば，コンパイル時に型エラーを捕捉しつつ，動的型付け言語の読みやすさを実現できるのです．

- 関数がジェネリックである，すなわち単一の関数が複数の型の値で動作します．  
  Python や JavaScript では，全ての関数がこのような動作をします．関数で必要なプロパティやメソッドを備えていれば，どんな値でも処理できるのです (このような特性はしばしば duck typing と呼ばれます．アヒルのように鳴くなら，それはアヒルということです)．しかし，このような柔軟性のせいで，早期に型エラーを発見するのが難しくなっているのです．そのような型エラーを見つけるにはテストするしかありません．一方，Rust のジェネリック関数は柔軟性を持たせつつも，あらゆる型エラーをコンパイル時に検出できます．
  ジェネリック関数は，その柔軟性にもかかわらず，非ジェネリック関数と同じように効率的です．例えば，各整数に対して特定の sum 関数を書いたとしても，すべての整数を扱うジェネリック関数を書いた場合と比較して，本質的な性能上の優位性はありません，ジェネリック関数については第11章で詳しく説明します．

本章では以降，整数型のようにシンプルな数値型や浮動小数点型の値から始めて，ボックスやタプル，配列や文字列のような多くのデータを保持できる型を見ていきます．  
以下に，Rust に登場するプリミティブな型をまとめておきます．

| 型 | 説明 | 値 |
| :--: | :-- | :--|
| i8, i16, i32, i64, i128, u8, u16, u32, u64, u128 | ビット幅指定のある符号付き/符号なしの整数型 | 42, -5i8, 0x400u16, 0o100i16, 20_922_789_888_000u64, b'*' (u8 バイトのリテラル) |
| isize, useize | 符号付き/符号なしの整数でマシンのアドレスと同じサイズ (32bit or 64bit) | 137, -0b0101_0010isize, 0xffff_fc00usize |
| f32, f64 | IEEE の浮動小数点数で単精度と倍精度 | 1.61803, 3.14f32, 6.0221e23f64 |
| bool | Boolean | true, flase |
| char | 32ビット幅の Unicode 文字 | '*', '\n', '字', '\x7f', '\u{CA0}' |
| (char, u8, i32) | タプル (Tuple): 複数の型の混合を許容 | ('%', 0x7f, -1) |
| () | Unit (空のタプル) | () |
| struct S { x: f32, y: f32 } | 名前付きフィールドを持つ構造体 | S { x: 120.0, y: 209.0 } |
| struct T (i32, char); | タプルに似た構造体 | T(120, 'X') |
| struct E; | フィールドを持たない Unit のような構造体 | E |
| enum Attend { OnTime, Late(u32) } | 列挙型で代数的なデータ型 | Attend::Late(5), Attend::OnTime |
| Box\<Attend> | ボックス型でヒープの値の owning ポインタ | Box::new(Late(15)) |
| &i32, &mut i32 | 共有されたミュータブルな参照で参照元より寿命の短い non-owning ポインタ | &s.y, &mut v |
| String | UTF-8 の文字列で可変長 | "ラーメン: ramen".to_string() |
| &str | str への参照で UTF-8 テキストの non-owning ポインタ | 	"そば: soba", &s[0..12] |
| [f64; 4], [u8; 256] | 配列で固定長かつ要素は全て同じ型 | [1.0, 0.0, 0.0, 1.0],　[b' '; 256] |
| Vec\<f64> | ベクトル型で可変長かつ要素は全て同じ型 | vec![0.367, 2.718, 7.389] |
| &[u8],&mut [u8] | スライスへの参照でポインタと長さを含む配列やベクトルに対する参照 | &v[10..20], &mut a[..] |
| Option\<&str> | None か Some(v) のいずれかの値 | Some("Dr."), None |
| Result\<u64, Error> | 成功時の Ok(v) とエラー時の Err(e) をまとめた値 | Ok(4096), Err(Error::last_os_error()) |
| &dyn Any, &mut dyn Read | トレイトオブジェクトで与えられたメソッドを実装するあらゆる型に対する参照 | value as &dyn Any, &mut file as &mut dyn Read |
| fn(&str) -> bool | ポインタ関数 | str::is_empty |
| クロージャには明記すべき型はない | クロージャ | |a, b| { a*a + b*b } |

ほとんどの型はここで紹介しますが，一部は別の章で扱います

- ```struct``` 型 : [第9章](../ch09)
- ```enum``` (列挙) 型 : [第10章](../ch10/)
- トレイトオブジェクト : [第11章](../ch11/)
- ```String``` 型と ```&str``` の詳細 : [第17章](../ch17/)
- 関数型とクロージャ型 : [第14章](../ch14/)

## 目次
- 3-1. [固定長の数値型](./1_Fixed-Width_Numeric_Types.md)
- 3-2. [ブール型](./2_The_bool_Type.md)
- 3-3. [文字型](./3_Characters.md)
- 3-4. [タプル](./4_Tuples.md)
- 3-5. [ポインタ型](./5_Pointer_Types.md)
- 3-6. [配列，ベクトル，スライス型](./6_Arrays_Vectors_and_Slices.md)
- 3-7. [文字列型](./7_String_Types.md)
- 3-8. [型エイリアス](./8_Type_Aliases.md)
- 3-9. [高度な話題](./9_Beyond_the_Basics.md)

# 3-3. 文字
Rust の文字型 ```char``` は単一の Unicode で表される32ビットの値です．

Rust は ```char``` 型を単独の1文字を表すのに使っていますが，文字列やテキスト・ストリームのエンコードには UTF-8 を使っています．
そのため，文字の配列としてではなく，```String``` は UTF-8 のシーケンスとして表現されます．

文字リテラルはシングルクオート (```'```) で囲まれた文字です．
Unicode に含まれる文字であれば全て利用できますが，次に示す文字にはバックスラッシュによるエスケープが必要です．

| 文字 | 文字リテラル |
| :--: | :--: |
| シングルクオート | ```'\''``` |
| バックスラッシュ | ```'\\'``` |
| 改行 | ```'\n'``` |
| 行頭復帰 | ```'\r'``` |
| タブ | ```'\t'``` |

Unicode の16進数コードで直接文字を書き出すこともできます．

- ASCII に含まれる U+0000 から U+007F までの文字コードの場合，```'\xHH'``` 形式で記述できる (ただし ```HH``` は2桁の16進数)
- Unicode は ```'\u{HHHHHH}'``` という最大6桁の16進数で記述し，アンダースコアの併用も可能

```char``` 型は，常に ```0X0000``` から ```0XD7FF```，あるいは ```0XE000``` から ```0X10FFFF``` の範囲の値を取ります．
```0XD800``` から ```0XDFFF``` までの値や ```0X10FFFF``` より大きい値は取りません．
Rust では型システムと動的なチェックによって，文字型の値がこの範囲にあることを確認しています．

文字型から暗黙的に他の型に変換されることはありませんが，```as``` によって整数型に変換できます．
変換先の型が32ビット未満の場合には，文字の上位ビットが丸められます．

```rust
assert_eq!('*' as i32, 42);
assert_eq!('ಠ' as u16, 0xca0);
assert_eq!('ಠ' as i8, -0x60); // U+0CA0 truncated to eight bits, signed
```

```u8``` 型だけは ```as``` によって ```char``` 型に変換できます．
Rust は安価で確実な変換のみを ```as``` 演算子で行うことを意図しています．
しかし，```u8``` 以外の整数型は Unicode で許可されていない値を取り得るため，これらの変換には実行時のチェックが必要になります．
その代わり，標準ライブラリでは，任意の ```u32``` 型の値を取って ```Option<char>``` を返す ```std::char::from_u32``` という関数が提供されています．
もし ```u32``` の値が Unicode のコードポイントとして許可されていなければ ```None``` を返し，それ以外の場合には ```Some(c)``` (```c``` は ```char``` 型の結果) を返します．

標準ライブラリでは，文字に関する便利なメソッドがいくつか用意されています．
詳細はオンライン・ドキュメントの "char (primitive type)" 及び "std::char" の項を見て下さい．

```rust
assert_eq!('*'.is_alphabetic(), false);
assert_eq!('β'.is_alphabetic(), true);
assert_eq!('8'.to_digit(10), Some(8));
assert_eq!('ಠ'.len_utf8(), 3);
assert_eq!(std::char::from_digit(2, 10), Some('2'));
```
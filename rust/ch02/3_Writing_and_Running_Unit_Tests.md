# 2-3. ユニットテストを書いて実行する
Rust では簡単にテストを記述できます，
例えば，先ほど定義した ```gcd``` 関数と同じファイルの最後に，次のようなテストコードを書き加えるだけです．

```rust
#[test]
fn test_gcd() {
    assert_eq!(gcd(14, 15), 1);

    assert_eq!(gcd(2 * 3 * 5 * 11 * 17,
                   3 * 7 * 11 * 13 * 19),
               3 * 11);
}
```

```test_gcd``` という ```gcd``` 関数をテストする関数を定義しています．
```#[test]``` はテスト用の関数であることを表しています．
通常のコンパイル時には無視されますが，```cargo test``` が実行されたときに呼び出されます．
テスト用関数は通常，関数のすぐ後に置かれますが，コードのどこに置いてあっても，自動的に全てのテストが実行されます．

```#[test]``` は属性 (attribute) の一例です．
属性は，関数やその他の宣言に付加的な情報を与えるシステムで，コンパイラの警告やコードスタイルのチェックを制御したり，条件付きでコードをインクルードしたり，ほかの言語で書かれたコードとの相互作用について指示したりするのに使われます．

先ほど作成した ```hello``` パッケージの ```main.rs``` に ```gcd``` と ```test_gcd``` を追記して，```cargo test``` を実行してみましょう．

```bash
$ cargo test
   Compiling hello v0.1.0 (/workspace/rust/ch02/hello)
    Finished test [unoptimized + debuginfo] target(s) in 0.23s
     Running unittests (target/debug/deps/hello-5eff316739449516)

running 1 test
test test_gcd ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s
```
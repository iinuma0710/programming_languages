# 3-8. 型エイリアス
```type``` キーワードは C++ の ```typedef``` のように，既存の型に新しく名前をつけることができます．

```rust
type Bytes = Vec<u8>;
```

ここで宣言した ```Bytes``` 型は，この ```Vec``` 型の短縮記法として使えます．

```rust
fn decode(data: &Bytes) {
    ...
}
```

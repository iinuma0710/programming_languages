# 2-2. Rust の関数
Rust の関数定義は他のプログラミング言語とほとんど同じです．
次の関数は，ユークリッドアルゴリズムで最大公約数を求める関数です．

```rust
fn gcd(mut n: u64, mut m: u64) -> u64 {
    assert!(n !=0 && m != 0);
    while m != 0 {
        if m < n {
            let t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    n
}
```

```fn``` は関数定義するキーワードで，```n``` と ```m``` という2つのパラメータを取る関数 ```gcd``` を定義しています．
パラメータはそれぞれ符号なし整数 (```u64```) で ```->``` によって返り値の方を指定します．
インデントは空白4つが Rust の標準スタイルです．  

Rust の整数はそのサイズと符号の有無で表します．
```i32``` は符号付き32ビット整数を，```u8``` は符号なし8ビット整数をそれぞれ表します．
```isize``` と ```usize``` でシステムのポインタサイズを取得できます．
これらは，32ビットシステムでは32，64ビットシステムでは64となります．
また，浮動小数点数の型として ```f32``` と ```f64``` が用意されており，C や C++ では ```float``` と ```double``` に該当します．  

デフォルトでは，一度変数が初期化されると，その値は変更できなくなります．
しかし，```mut``` キーワードをパラメータの前に置くと，関数内で値を割り当てることができるようになります．  

```assert!``` の ```!``` はマクロの呼び出しを表します．
C や C++ の ```assert``` マクロと同様に，引数が True であることを確認し，False であればコードで失敗した箇所を含むメッセージを吐いてプログラムが終了します．
これを「パニック」と呼びます．
ただ，```assert``` をスキップできる C や C++ とは異なり，Rust ではコンパイル方法にかかわらず必ず評価されます．
速度向上に向けてコンパイルした場合にスキップされる ```debug_assert!``` というマクロもあります．

```while``` や ```if``` は C や C++ と異なり，条件式に括弧は不要です．
ただし，ステートメントには波括弧を付ける必要があります．

ローカル変数の宣言には ```let``` を用います．
変数の使い方から方が推定でき場合には，型を明記する必要はありません．
上記の例では，```t``` は ```m``` や ```n``` と同じ ```u64``` 型しか取り得ません．
Rust の型推論は関数の本体でのみ有効で，パラメータと返り値の型は明示的に示す必要があります．
```t``` の定義をちゃんと書くと次のようになります．

```rust
let t: u64 = m;
```

Rust には ```return``` ステートメントがありますが省略可能です．
関数の末尾でセミコロンを付けずに式や変数を記述した場合，それが関数の返り値として返されます．
Rust では波括弧で囲まれたブロックは式として機能します．
例えば，次のコードは文字列を表示した後，```x.cos()``` をその値として返します．

```rust
{
    println!("evaluating cos x");
    x.cos()
}
```

Rust では上記のような方法で関数が「完了した」ことを通知して値を返すという形式を良く用います．
```return``` を用いるのは，関数の途中で明示的に値を返す場合だけです．
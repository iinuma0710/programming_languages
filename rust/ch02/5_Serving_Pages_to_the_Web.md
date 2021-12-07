# 2-5. Web にページを貼り出す
Rust の強みの一つに，[crate.io](https://crate.io) から ```cargo``` コマンドを使って簡単にライブラリを取得できる点が挙げられます．
Rust のパッケージは，ライブラリであろうと実行可能ファイルであろうとクレート (crate) と呼ばれます．
ここでは，ウェブフレームワークの ```actix-web``` とシリアル化を行う ```serde``` クレートを用いて Web サーバーを立ち上げます．

```cargo new``` コマンドで ```actix-gcd``` プロジェクトを作成します．
生成された ```Cargo.toml``` を次のように書き換えます．

```toml
[package]
name = "actix-gcd"
version = "0.1.0"
edition = "2021"

# See more keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

[dependencies]
actix-web = "1.0.8"
serde = { version = "1.0", features = ["derive"] }
```

```[dependences]``` 以下の各行で，必要なパッケージとそのバージョンを指定しています．
上の例のように，バージョンを指定しておけば，新しい crate バージョンが公開された後でも，パッケージのバージョンは固定となります．
パッケージのバージョン管理は第8章で詳しく説明します．

必ずしも必要というわけではありませんが，クレートには ```features``` オプションを指定できます．
```features``` オプションではインターフェイスや実装を指定できます．
```serde``` は Web フォームのデータを処理するクレートですが，```derive``` を選択したときのみ利用可能なので，そのように指定しています．

注意すべきは，直接使うクレートのみを指定すればよいということです．
```cargo``` コマンドを使えば，ほかの依存関係は良しなに処理してくれます．

まず，```actix-gcd/src/main.rs``` に次の内容を書き込んでください．

```rust
use actix_web::{web, App, HttpResponse, HttpServer};

fn main() {
    let server = HttpServer::new(|| {
        App::new()
            .route("/", web::get().to(get_index))
    });

    println!("Serving on http://localhost:3000...");
    server
        .bind("127.0.0.1:3000").expect("error binding server to address")
        .run().expect("error running server");
}

fn get_index() -> HttpResponse {
    HttpResponse::Ok()
        .content_type("text/html")
        .body(
            r#"
                <title>GCD Calculator</title>
                <form action="/gcd" method="post">
                <input type="text" name="n"/>
                <input type="text" name="m"/>
                <button type="submit">Compute GCD</button>
                </form>
            "#,
        )
}
```

初めに，```actix-web``` を ```use``` を使って読み込みます．
```{web, App, ...}``` のように波括弧で括ることで，まとめてモジュールを読み込めます．  
メイン関数では ```HttpServer::new``` を使って3000番ポートに来た ```/``` というパスへのリクエストにメッセージを返すサーバを立てています．
```HttpServer::new``` の引数には，```|| { App::new() ... }``` のようにクロージャ (closure)を渡しています．
クロージャは関数のように呼び出すことのできる値です．
ここでは引数を取っていませんが，引数がある場合には ```||``` の間に指定してやります．
そして，波括弧の中身がクロージャの本体になります．
サーバを起動すると Actix は入ってくるリクエストを処理するためにスレッドのプールを開始します．
各スレッドはクロージャーを呼び出して，リクエストのルーティングや処理方法を指示する ```App``` の値の新しいコピーを取得します．  
クロージャでは ```App::new()``` で新しい空の ```App``` を作成し，```route``` メソッドを呼び出して ```/``` に対するパスを追加しています．
```route``` メソッドには，```get_index``` 関数を呼び出して HTTP の GET リクエストを扱うハンドラ (```web::get().to(get_index)```) を渡しています．
```route``` メソッドは最初に作った ```App``` に新しいルートを追加して返しています．
クロージャの最後にはセミコロンが付いていないので，この ```App``` が返り値となります．  


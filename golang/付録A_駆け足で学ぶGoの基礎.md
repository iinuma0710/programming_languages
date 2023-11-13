# 付録 A 駆け足で学ぶ Go　の基礎
Go の基礎的な文法をおさらいします．

## A.1 Hello World
まずは，"Hello World" を表示するモジュールを作成します．
Go では1つのフォルダを1つのモジュールとして扱います．
モジュールを作成するには，はじめに次のコマンドで ```go.mod``` ファイルを作成します．

```bash
$ go mod init helloworld
```

次に，```main.go``` ファイルを作成します．

```go
package main

import ( "fmt" )

func main() {
    fmt.Println("Hello World")
}
```

それでは，ビルドして実行してみましょう．

```bash
$ go build
$ ./helloworld
Hello World
```

Go のプログラムでは，最初にパッケージ名を記述します．
また，```main``` パッケージは必ず作成する必要があり，```main``` パッケージの ```main()``` 関数から実行が開始されます．

## A.2 リテラル・変数宣言
リテラルには整数や浮動小数点数，ブール型，文字列，```nil``` があります．
```nil``` は初期化されていない無効な参照先を表す値です．  
変数は ```var``` キーワードの後ろに変数名と型を記述します．
また，代入によって値を設定することもできます．
その場合，代入する値によって変数の型が推論できるので，型が省略可能です．

```go
var num1 int = 123
var num2 = 456
```

関数の中では ```:=``` を使った変数の宣言と代入が可能です．

```go
num3 := 789
```

Go では宣言するだけで使わない変数があるとエラーとなります．
また，定義だけして初期化しないと，ゼロ値が設定されます．

### A.2.1 シャドーイング
Go では以下に示す例のように，コードブロックの内側でネストして変数の宣言が可能です．

```go
x := 1
if condition {
    // x を再宣言
    x := 2

    // "x = 2"
    fmt.Println("x =", x)
}

// "x = 1"
fmt.Println("x =", x)
```

## A.3 名前
パッケージ名は全て小文字でつけますが，パッケージレベルの関数や変数，型の命名は，

- camelCase か CamelCase としアンダースコアなどを付けない
- 先頭が大文字ならパッケージ街からも利用可能となるが，小文字の場合には内部利用のみ

というルールになっています．
関数内の変数や引数では，

- 宣言場所から近い場所で利用し，説明がなくても良いものは1文字などできる限り短く
- エラーは ```err```，コンテキストは ```ctx```

というルールになっています．

# A.4 コメント
行コメント ```//``` とブロックコメント ```/* */``` があります．
このうち，空行なして関数や型の宣言の直前に空行なしで書かれたコメントは，その要素のドキュメントとして利用されます．

```go
// this function is to do something
func CommentedFunc() {
    ...
}
```

# A.5 型と変換
Go ではリテラルの状態では型を持っておらず，変数に代入した時点で型が決まります．
同じ数値であっても暗黙の型変換は行われず，明示的に型を示して変換し，変数に代入する必要があります．

```go
var i int = 123

// 数値同士の変換
var f float64 = float64(i)

// int と int64 でも型変換を明示する必要がある
var i64 int64 = int64(i)

// bool への変換は比較演算子を使う
var b bool = i != 0
```

文字列型と数値型との相互変換には ```strconv``` パッケージを利用します．
文字列型から数値型への変換は ```Parse``` から始まる関数を，逆の場合は ```Format``` から始まる関数をそれぞれ利用します．

```go
in := 12345

// strconv の数値入力は int64, uint64, float64 なのでそれ以外の変数を使う時は型変換が必要
s := strconv.FormatInt(int64(in), 10)
// s = "12345"

// Parse 系はエラー変換失敗時にエラーを返す
// 成功時の err は nil
f, err := strconv.ParseFloat("12.3456", 64)
// f = 12.3456, err = nil
```

# A.6 ポインタ
ポインタは，変数に格納されたデータのメモリ上におけるアドレスを扱う機能です．
Go では次のように使われます．

- 変数のポインタ型には ```*``` を前置する
- 既存の変数のポインタを取り出すには ```&``` を利用する
- ポインタから参照先の値を取り出す場合には ```*``` を利用する

最後の操作はデリファレンスとも呼ばれます．

```go
// ポインターの参照先となる普通の変数
var i int = 10 

// ポインターを格納する変数（デフォルト値は nil） 
var p *int

// p には i のアドレスが入る
p = &i 

// p 経由で i の値を取得
fmt.Println(*p)
```

ポインタ型は初期値が ```nil``` で，```nil``` の参照先を取り出そうとすると，プログラムがパニックを起こして終了します．
リテラルは変数に格納されるまで参照を取得できませんが，関数やスライス，マップなどは参照型と呼ばれ，ポインタと同等の動きをします．

## A.7 ゼロ値
宣言して値を設定していない変数は，ゼロ値で初期化されます．
それぞれの型は，次のようなゼロ値で初期化されます．

| 型 | ゼロ値 |
| :--: | :--: |
| 数値型 | 0 |
| ブール型 | false |
| 文字列 | 空文字列 |
| ポインタ | nil |
| インタフェース | nil |

ゼロ値による初期化によって，開発のしやすさや安全性を向上させています．

## A.8 スライス
Go には同じ型のデータが複数並んだデータ構造として配列とスライスがあります．
どちらも，要素の型の前にブラケットを前置したものが型名となり，ブレースを後置するとインスタンスが生成されます．
ただし，配列がブラケットの中に要素数を記述する一方で，スライスは要素数が不定となっています．

Go の配列は固定長となるため，スライスと比べてあまり使われません．

```go
// 要素数 3 の整数の配列 
var nums [3]int = [3]int{1, 2, 3}

// 要素の値を取り出して表示 
fmt.Println(nums[0])

// 長さを取得 
fmt.Println(len(nums))
```

スライスは，参照している配列，配列中の要素数，配列の容量の3つのデータから構成されています．
配列と同様，任意の位置にあるデータを取得できることに加え，```append()``` 関数を用いて要素を追加することができます．
参照している配列が容量の上限に達した場合には，自動的に2倍のサイズのメモリを新たに確保してデータを載せ替えます．

```go
// スライスの変数宣言
var nums1 []int

// 1, 2, 3 の要素を持つスライスを作成して代入
nums2 := []int{1, 2, 3}

// あるいは既存の配列やスライスからも範囲アクセスでスライス作成 
nums3 := nums[0:2] // 配列から
nums4 := nums2[1:3] // スライスから

// 配列と同じようにブラケットで要素取得可能，範囲外アクセスはパニック 
fmt.Println(nums2[1]) // 2

// 要素の割り当ても可能
nums2[0] = 100

// 長さも取得可能
fmt.Println(len(nums2)) // 3

// スライスに要素を追加，再代入が必要
nums2 = append(nums2, 4)
```

厳密にはスライスと可変長配列は同じものではありませんが，実用上は同等のものとして扱われます．
また，配列の範囲外にアクセスしようとするとパニックを起こして強制終了するように設計されており，セキュリティ面でリスクのある操作をエラーとして扱うようになっています．

# A.9 マップ
Go のマップは次のような形式で提供される複合型です．

- 型は ```map[キーの型]値の型```
- ブレースをつけるか ```make()``` 関数を用いた初期化が必須
- 値の割り当てと取得にはブラケットを取得

```go
// 数字がキーで値が文字列のマップ
// HTTP ステータスを格納 
hs := map[int]string{
    200: "OK",
    404: "Not Found",
}

// make で作る
authors := make(map[string][]string)

// ブラケットで要素アクセス，代入
authors["Go"] = []string{"Robert Griesemer", "Rob Pike", "Ken Thompson"}

// データ取得
status := hs[200] fmt.Println(status) // "OK"

// 存在しない要素にアクセスするとゼロ値
fmt.Println(hs[0]) // panic

// あるかどうかの情報も一緒に取得
status, ok := hs[304] // status = "", ok = false
```

## A.10 制御構文
### A.10.1 if
```if``` 文の条件節は，必ずブール型でなければなりません．

```go
if statusCode == 200 {
    fmt.Println("no error")
} else if statusCode < 500 {
    fmt.Println("client error")
} else {
    fmt.Println("server error")
}
```

上記のような基本的な使い方以外にも，変数宣言とセットで用いることが可能です．

```go
if res, ok := cache[input]; ok {
    fmt.Println("cached value", res)
}
```

### A.10.2 for ループ
最もよく使われるのは，```range``` と組み合わせてスライスやマップの全要素を取り出すループです．

```go
scketches := []string{"Dead Parrot", "Killer joke", "Spanish Inquisition", "Spam"}
for i, s := range scketches {
    fmt.Println(i, s)
}
```

代入先の変数を1つだけ指定すると，スライスのインデックスかマップのキーが代入されます．
それぞれの値だけが欲しい場合には，```_``` (ブランク識別子) でインデックスやキーを読み飛ばします．

```go
// 1変数の時はインデックスのみを取り出す
for i := range scketches { 
    fmt.Println(i)
}

// ブランク識別子でインデックスを読み飛ばして値だけを使う 
for _, s := range scketches {
    fmt.Println(s)
}
```

```break``` でループを強制終了させたり，```continue``` で次のループに処理を飛ばすことも可能です．
また，ブール型の要素を1つだけ持つ ```for``` を使って，条件を満たしている限り回り続けるループを作ったり，全て省略することで無限ループさせたりすることもできます．

```go
counter := 0
for counter < 10 {
    fmt.Println(" ブール値が true の間回り続けるループ ")
    counter += 1
}

end := time.Now().Add(time.Second)
for { 
    fmt.Println("break や return で抜けないと終わらないループ ")
    if end.Before(time.Now()) {
        break
    }
}
```

さらに，初期化節，ループ条件節，ループごとの処理節からなる，プリミティブなループ処理も実現可能です．

```go
for i := 0; i < 10; i++ {
    fmt.Println("10回繰り返す")
}
```

### A.10.3 switch
条件式を ```switch``` に書き，```case``` 節に式の値ごとの処理を書くことで，```if ... else if``` と同じ動作をする制御文です．
```default``` 節にどの条件にも当てはまらなかった場合の処理を記述します．

```go
switch s {
    case "running":
        fmt.Println(" 実行中 ")
    case "stop":
        fmt.Println(" 停止中 ")
    default:
        fmt.Println(" その他 ")
}
```

C/C++ の ```switch``` 文とは異なり，上から順に値を確認し，マッチした節の処理が終了すると ```switch``` の制御から抜けます．
処理を継続する場合には，```fallthrough``` をおく必要があります．

## A.11 関数
Go では関数も複合型の1種として扱われ，引数と返り値を持ちます．
基本的に関数は次のように定義できますが，同じ型の引数や返り値が連続する場合には，型の記述を省略できます．

```go
func func_name(arg1, arg2 int) int {
    return arg1 + arg2
}
```

返り値に名前をつけることも可能で，返り値用の変数に値を代入して，何も付けずに ```return``` すれば，その変数に格納された値が返されます．
この時，返り値を括弧で括る必要があります．

```go
func calcAge(y int, m time.Month, d int) (age int, err error) {
    b := time.Date(y, m, d, 0, 0, 0, 0, time.Local)
    n := time.Now()
    if b.After(n) {
        err = errors.New(" 誕生日が未来です ")
        return
    } 
    for {
        b = time.Date(y+age+1, m, d, 0, 0, 0, 0, time.Local)
        if b.After(n) {
            return
        }
        age++ 
    }
}
```

Go の無名関数は，コールバックを受け取る場所で一緒に定義することも可能です．
次の例では，```func(int, int) int``` 型となる無名関数を変数に代入して他の関数に渡したり，他の関数の呼び出し時点で無名関数を定義したりしています．

```go
m := func(x, y int) int {
    return x * y
}

func doCalc(x, y int, f func(int, int) int) {
    fmt.Println()
}

// 名前付きで定義した関数以外に、無名関数として定義したものを渡せる
doCalc(10, 20, m)

// その場で定義した関数も渡せる
doCalc(10, 10, func(x, y int) int {
    return x * y
})
```

### A.11.1 defer であと処理関数の実行予約
Python の ```with``` 句と同様，処理の開始と同時に処理の後処理を予約できる機能が用意されています．
```defer``` 節の処理がスコープを抜けたタイミングで実行されます．

```go
// ファイルを開く
f, err := os.Create("sample.txt")
if err != nil {
    fmt.Println("err", err)
    return
}
// この関数のスコープを抜けたら自動でファイルをクローズ
defer f.Close()
io.WriteString(f, "hello world")
```

## A.12 エラー処理
Go に例外処理は存在せず，次のようなルールでエラー処理を行います．

- 失敗する可能性のある関数の末尾は ```error``` 型とする
- 成功時には ```nil``` を，失敗時には詳細なエラーを割り当てて返す
- 関数を呼び出した後は，```if err != nil``` でエラーチェックを行い，追加情報をラップしたり，そのまま ```return``` で呼び出し元に戻ったりする

## A.13 構造体
いくつかのデータをまとめて塊として扱えるようにしたものを構造体と呼びます．
構造体は次のように定義します．
メンバ変数についても名前を大文字から始めなければ，外部のパッケージから利用できなくなります．

```go
type StructName struct {
    Title string
    Author string
    Publisher string
    ReleasedAt time.Time
    ISBN string
}
```

他のプログラミング言語の構造体とは異なり，構造体の中にメソッドを定義することはできませんが，外側に定義することができるようになっています．  
構造体はあくまで型ですので，利用するには次のような方法で，メモリ上にインスタンスを作成する必要があります．

```go
// インスタンス作成 (フィールドはすべてゼロ値に初期化)
var b Book

// フィールドを初期化しながらインスタンス作成 
b2 := Book{
    Title: "Twisted Network Programming Essentials",
}

// フィールドを初期化しながらインスタンス作成し，変数にはポインターを格納 
b3 := &Book{
    Title: " カンフーマック――猛獣を飼いならす 310 の技 ",
}
```

業務アプリケーションの開発では，以下に示す例のように各フィールドに JSON タグを付与しておくことで，```encoding/json``` パッケージの関数を使って JSON を書き出したりロードしたりすることができます．

```go
package main

import (
    "encoding/json"
    "fmt"
    "log"
    "os"
    "time"
)

type Book struct {
    Title       string      `json:"title"`
    Author      string      `json:"author"`
    Publisher   string      `json:"publisher"`
    ReleasedAt  time.Time   `json:"release_at"`
    ISBN        string      `json:"isbn"`
}

func main() {
    f, err := os.Open("book.json")
    if err != nil {
        log.Fatal("file open error: ", err)
    }
    d := json.NewDecoder(f)
    var b Book
    d.Decode(&b)
    fmt.Println(b)
}
```

## A.14 ライブラリのインポート
VS Code や GoLand を使っていれば，標準ライブラリやインストール済みのライブラリを途中までタイプした時点で自動補完機能によって，```import``` 文まで自動で生成してくれます．  
Go では中央集権的なライブラリのリポジトリがないため，次のようなコマンドで GitHub や GitLab になどから，URL を指定してライブラリをインストールします．

```bash
$ go get github.com/rs/zerolog
go: downloading github.com/rs/zerolog v1.26.1
go: added github.com/rs/zerolog v1.26.1
```

## A.15 ウェブアプリケーション
以下に，文字列を返すだけの簡単なアプリケーションの例を示します．

```go
package main

import (
    "fmt"
    "io"
    "net/http"
    "os"
    "github.com/rs/zerolog/log"
)

func main() { 
    // ① 
    http.HandleFunc("/hello", func(w http.ResponseWriter, r *http.Request) {
        fmt.Fprintf(w, "Hello, World")
        log.Info().Msg("receive hello world request")
    })

    // ②
    fmt.Println("Start listening at :8080")
    // ③ 
    err := http.ListenAndServe(":8080", nil)
    if err != nil {
        // ④
        fmt.Fprintf(os.Stderr, "")
        io.WriteString(os.Stderr, err.Error())
        os.Exit(1)
    }
}
```

1. URL ごとの処理を登録 (ここでは ```/hello``` にアクセスした場合の処理を記載)
2. 画面にテキストを表示
3. ```http``` パッケージの ```ListenAndServe()``` 関数でサーバを起動
4. 対象のポートが使用されていたらエラーを表示してプログラムを終了

実際のアプリケーションでは，JSON 形式のリクエストやレスポンスの読み書きや，データベース機能の利用が必要になります．

## A.16 まとめ
Go の特徴として，並列処理のやりやすさが挙げられることもありますが，学習コストが低いことも大きなメリットとなります．
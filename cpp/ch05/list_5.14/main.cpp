#include <iostream>
#include <string>

class A
{
    int m_v;
    std::string m_n;

public:

    A(int, std::string);
    A(float);
};

// メンバの初期化リストでもブレースを使える
A::A(int v, std::string n) : m_v{v}, m_n{n} {}

// 委譲コンストラクタでもブレースを使える
A::A(float) : A{-1, "float"} {}

int main()
{
    A ap(42, "0");  // 括弧を使った初期化
    A ab{42, "0"};  // ブレースを使った初期化

    A bp = A(42, "0");  // 関数形式の明示的な型変換
    A bb = A{42, "0"};  // 関数形式でブレースを使っても意味は同じ

    A cp = (42, "0");   // bp の初期化と同じ意味にはならずエラーとなる
    A cb = {42, "0"};   // bb の初期化と同じ意味

    A dp = (42, 0.0);   // エラーとはならないが、 A(float) が呼ばれる
    A db = {42, 0.0};   // double -> string は型変換できないためエラー

    double pi = 3.1415926536;
    A ep(pi);   // double -> float の暗黙の型変換が行われるがエラーではない
    A eb{pi};   // 安全な型変換が保証されないのでエラー
}

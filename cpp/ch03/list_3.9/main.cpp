#include <iostream>

class A
{
    int m_v;

public:
    // 暗黙のコンストラクタ呼び出しを禁止
    explicit A(int);

    int v() const;
};

A::A(int v) : m_v(v) {}

int A::v() const
{
    return m_v;
}

int main()
{
    A x = 0;    // エラーになる (暗黙のコンストラクタ呼び出し)
    A y(42);    // 明示的なコンストラクタ呼び出し
    y.v() == 42;    // true
}
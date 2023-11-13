#include <iostream>

class A
{
public:
    operator int() const { return 0; }
};

class B
{
public:
    // explicit 指定された int への変換関数
    explicit operator int() const { return 0; }
};

int main()
{
    A a;
    int ia = a;     // 変換関数は explicit 指定されていないので OK
    char ca = a;    // int に暗黙変換された後 char に代入されるので OK

    B b;
    int ib = b;     // 変換関数が explicit 指定されているので B から int への暗黙変換は行われずエラーとなる
    char cb = b;    // 上と同じく暗黙変換は行われないのでエラーとなる

    int j(b);       // 変数 j は変換関数の戻り値で初期化される
    int k = static_cast<int>(b);    // 明示的にキャストすれば変換関数が呼ばれる
}

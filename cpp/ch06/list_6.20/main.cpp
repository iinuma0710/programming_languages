#include <iostream>

class A
{
public:
    void foo() { std::cout << "A::foo" << std::endl; }
};

class B
{
    A a;

public:
    // メンバ変数を返す変換関数
    operator A&() { return a; }
};

int main()
{
    B b;
    b.foo();    // B はメンバ関数 foo を持たないのでエラー
}
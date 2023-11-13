#include <iostream>

class Base
{
public:
    void foo();
};

void Base::foo()
{
    std::cout << "Base::foo()" << std::endl;
}

class Derived : public Base
{
public:
    using Base::foo;    // 基底クラスの foo() を呼び出せるようにする
    void foo(int v);    // オーバロード
};

void Derived::foo(int v)
{
    std::cout << "Derived::foo(" << v << ")" << std::endl;
}

int main()
{
    Derived derived;
    derived.foo();
    derived.foo(42);
}
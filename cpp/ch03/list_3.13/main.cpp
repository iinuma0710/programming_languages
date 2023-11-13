#include <iostream>

class Base
{
public:
    virtual void foo();
};

void Base::foo()
{
    std::cout << "Base::foo()" << std::endl;
}

class Derived : public Base
{
public:
    void foo() override;            // メンバ関数をオーバライド
    // void foo(int i) override;    // 対応する仮想関数が基底クラスないのでエラー
    void foo(int i);                // オーバロードは可能
};

void Derived::foo()
{
    std::cout << "Derived::foo() override" << std::endl;
}

void Derived::foo(int i)
{
    std::cout << "Derived::foo(i)" << std::endl;
}

int main()
{
    Derived derived;
    derived.foo();
    derived.foo(42);
}
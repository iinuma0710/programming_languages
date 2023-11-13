#include <iostream>

class Base
{
public:
    virtual void method();
};

void Base::method()
{
    // 基底クラスでは派生クラスから呼び出されることを期待して実装
    std::cout << "Base::method()" << std::endl;
}

class Derived : public Base
{
public:
    // Base::method() をオーバライド
    void method() override;
};

void Derived::method()
{
    std::cout << "Derived::method()" << std::endl;
    Base* base = this;  // 基底クラスへのポインタを取得
    Base::method();     // クラスを指定して基底クラスのメンバ関数を呼び出す
    // base->method();  // Derived::method() の再起呼び出しとなり停止しなくなる
}

int main()
{
    Derived derived;
    derived.method();   // オーバライドしたメンバ関数の呼び出し
}
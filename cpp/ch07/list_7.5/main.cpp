#include <iostream>

class Base
{
public:
    virtual void method();
};

void Base::method()
{
    std::cout << "Base のメンバ関数" << std::endl;
}

class Derived : public Base
{
public:
    // Base::method() をオーバライド
    void method() override;
};

void Derived::method()
{
    std::cout << "Derived でオーバライドしたメンバ関数" << std::endl;
}

int main()
{
    Derived derived;
    Base& base = derived;   // 基底クラスへの参照

    // 基底クラスへの参照経由でも、仮想関数はオーバライドされた関数が呼ばれる
    base.method();
}
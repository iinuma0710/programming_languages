#include <iostream>

class Base
{
public:
    void method_Base();
};

void Base::method_Base()
{
    std::cout << "Base::method_Base()" << std::endl;
}

class Derived : public Base
{
public:
    void method_Derived();
};

void Derived::method_Derived()
{
    std::cout << "Derived::method_Derived()" << std::endl;
}

int main()
{
    Derived derived;

    // Base のメンバ関数を継承しているので OK
    derived.method_Base();

    // メンバ関数の呼び出しも OK
    derived.method_Derived();

    // 基底クラスへの参照は派生クラスからも作れる
    Base& base = derived;

    // Base のメンバ関数へは Base の参照からアクセスできる
    base.method_Base();
}
#include <iostream>

class BaseA
{
public:
    void method_BaseA()
    {
        std::cout << "BaseA::method_BaseA()" << std::endl;
    }
};

class BaseB
{
public:
    void method_BaseB()
    {
        std::cout << "BaseB::method_BaseB()" << std::endl;
    }
};

class Derived : public BaseA, public BaseB  // 多重継承
{
public:
    void method_Derived()
    {
        std::cout << "Derived::method_Derived()" << std::endl;
    }
};

int main()
{
    Derived derived;

    derived.method_BaseA();     // 継承したメンバ関数の呼び出し
    derived.method_BaseB();     // 継承したメンバ関数の呼び出し
    derived.method_Derived();   // 派生クラスで定義したメンバ関数の呼び出し

    BaseA& base_a = derived;    // BaseA として扱うことができる
    // base_a.method_BaseB();   // BaseA の参照なので BaseB のメンバ関数は呼び出せない
    // base_a.method_Derived(); // BaseA の参照から派生クラスのメンバ関数は呼び出せない


    BaseB& base_b = derived;    // BaseB として扱うことができる
    // base_b.method_BaseA();   // BaseB の参照なので BaseA のメンバ関数は呼び出せない
    // base_b.method_Derived(); // BaseB の参照から派生クラスのメンバ関数は呼び出せない
}
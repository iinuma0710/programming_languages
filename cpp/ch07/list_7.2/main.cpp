#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base コンストラクタ" << std::endl; }
    ~Base() { std::cout << "Base デストラクタ" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived コンストラクタ" << std::endl; }
    ~Derived() { std::cout << "Derived デストラクタ" << std::endl; }
};

class MoreDerived : public Derived
{
public:
    MoreDerived() { std::cout << "MoreDerived コンストラクタ" << std::endl; }
    ~MoreDerived() { std::cout << "MoreDerived デストラクタ" << std::endl; }
};

int main()
{
    MoreDerived more_derived;
    std::cout << "オブジェクト構築完了" << std::endl;
}
#include <iostream>

class Base
{
public:
    void foo();
};

void Base::foo()
{
    std::cout << "foo()" << std::endl;
}

class Derived : public Base
{
public:
    void bar();
};

void Derived::bar()
{
    std::cout << "bar()" << std::endl;
}

int main()
{
    Base base;
    base.foo();

    Derived derived;
    derived.foo();
    derived.bar();
}
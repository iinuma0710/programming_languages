#include <iostream>

class Base
{
private:
    
    int value;

public:

    Base(int value) : value{value} {}
    void show();
};

void Base::show()
{
    std::cout << "this: " << this << std::endl
        << "this->value: " << this->value << std::endl;
}

class DerivedA : public Base
{
public:
    DerivedA(int value) : Base{value} {}
};

class DerivedB : public Base
{
public:
    DerivedB(int value) : Base{value} {}
};

class MoreDerived: public DerivedA, public DerivedB
{
public:
    MoreDerived(int d_a, int d_b) : DerivedA{d_a}, DerivedB{d_b} {}
};

int main()
{
    MoreDerived more_derived{42, 72};

    // DerivedA と DerivedB のどちらの Base::show() が使われるかわからない
    more_derived.show();

    // DerivedA と DerivedB のどちらの Base への参照が代入されるかわからない
    Base& base = more_derived;
    base.show();
}
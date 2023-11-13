#include <iostream>

class Base
{
    int value = 0;

public:
    void set_value(int value);
    int get_value() const;
};

void Base::set_value(int value)
{
    this->value = value; 
}

int Base::get_value() const
{
    return value;
}

// クラスから構造体が派生することも可能
struct Derived : Base
{
    // コンストラクタやデストラクタも実装できる
    Derived();
    ~Derived();
};

Derived::Derived()
{
    std::cout << "コンストラクタ" << std::endl;
}

Derived::~Derived()
{
    std::cout << "デストラクタ" << std::endl;
}

int main()
{
    Derived d;
    
    std::cout <<d.get_value() << std::endl;

    d.set_value(42);

    std::cout << d.get_value() << std::endl;
}
#include <iostream>

class Base
{
public:
    virtual ~Base() // 仮想デストラクタ
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "Derived::~Derived()" << std::endl;
    }
};

Base* allocate()
{
    // 派生クラスを動的確保し、基底クラスのポインタに変換して返す
    return new Derived{};
}

int main()
{
    auto ptr = allocate();  // 基底クラスへのポインタ

    delete ptr; // コンパイルは通るが問題のあるコード
}
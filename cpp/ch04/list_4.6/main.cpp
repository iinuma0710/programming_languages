#include <iostream>

class A
{
public:
    A();
    ~A();
};

A::A()
{
    std::cout << "コンストラクタの呼び出し" << std::endl;
}

A::~A()
{
    std::cout << "デストラクタの呼び出し" << std::endl;
}

A a;    // グローバル変数

int main()
{
    std::cout << "main() 関数" << std::endl;
}
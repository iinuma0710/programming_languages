#include <iostream>

class A
{
public:
    ~A();
};

A::~A()
{
    std::cout << "デストラクタの呼び出し" << std::endl;
}

void function_scope(int i)
{
    A a;    // 関数のスコープから抜けるとデストラクタが呼ばれる

    std::cout << "関数スコープ" << std::endl;

    if (i > 0)
    {
        return; // ここで呼び出し元に移る
    }

    std::cout << "if 文の後" << std::endl;
}

int main()
{
    function_scope(10);

    std::cout << std::endl;

    function_scope(-10);
}
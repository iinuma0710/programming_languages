#include <iostream>
#include <utility>
#include <memory>

class A
{
public:

    A()
    {
        std::cout << "コンストラクタ" << std::endl;
    }

    ~A()
    {
        std::cout << "デストラクタ" << std::endl;
    }
};

std::unique_ptr<A> allocate()
{
    std::cout << "allocate()" << std::endl;
    std::unique_ptr<A> ptr{new A{}};

    // 桃理領域の所有権を戻り値として関数スコープの外側に移動する
    return std::move(ptr);
}

int main()
{
    {
        std::unique_ptr<A> ptr; // nullptr で初期化される

        std::cout << "関数呼び出しの前" << std::endl;

        ptr = allocate();   // allocate() 関数が確保したメモリ領域の所有権を受け取る

        std::cout << "関数呼び出しの後" << std::endl;
    }
    std::cout << "スコープの後" << std::endl;
}
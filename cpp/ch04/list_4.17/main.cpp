#include <iostream>

// 名前空間 A
namespace A
{
    struct S
    {
        int a;
    };

    void foo()
    {
        std::cout << "A::foo()" << std::endl;
    }
}

// 名前空間 B
namespace B
{
    struct S
    {
        int b;
    };

    void foo()
    {
        std::cout << "B::foo()" << std::endl;
    }
}

int main()
{
    A::foo();
    B::foo();
    A::S sa;
    B::S sb;
}
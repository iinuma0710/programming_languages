#include <iostream>

void hello()
{
    std::cout << "hello, world" << std::endl;
}

void goodbye()
{
    std::cout << "goodbye, world" << std::endl;
}

int main()
{
    hello();

    std::cout << "hello, macro" << std::endl;

#define hello goodbye   // hello を goodbye で置き換え

    hello();

    // 文字列の中身はマクロで置き換わらない
    std::cout << "hello, macro" << std::endl;
}
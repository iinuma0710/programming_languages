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
#define hello goodbye   // hello を goodbye で置き換え

    hello();

#undef hello

    hello();
}
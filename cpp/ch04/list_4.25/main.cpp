#include <iostream>

void hello()
{
    std::cout << "hello, world" << std::endl;
}

#define id(name) name   // 引数で受け取ったものにそのまま置き換える関数型マクロ

int main()
{
    id(hello)();
}
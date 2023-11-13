#include <iostream>

int& id(int& i)
{
    return i;
}

int main()
{
    int i = 42;

    auto j = id(i); // j は参照？値？
    j = 0;  // 参照なら中身が変わるはず
    std::cout << i << std::endl;
}
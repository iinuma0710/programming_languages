#include <iostream>

int main()
{
    int&& i = 1;    // 1への右辺値参照
    i = 0;  // OK：i は左辺値

    if (1 == 0) // 1 == 0 となってしまったのか？
    {
        std::cout << "1 == 0" << std::endl;
    }
    else
    {
        std::cout << "1 != 0" << std::endl;
    }
}
#include <iostream>

int main()
{
    int array[] = {0, 1, 2, 3, 4};

    // for 文の中では 操作する各要素の型を推論できる
    for (auto e : array)
    {
        std::cout << e << std::endl;
    }
}
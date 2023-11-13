#include <iostream>

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    int(*ptr)[5] = &array;  // 配列へのポインタ

    for (int e: *ptr)   // ポインタなので間接演算子が必要
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    int (&ref)[5] = array;  // 配列への参照

    for (int e : ref)   // 参照なので間接参照演算子は不要
    {
        std::cout << e << std::endl;
    }
}
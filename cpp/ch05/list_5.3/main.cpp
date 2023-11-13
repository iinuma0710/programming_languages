#include <iostream>

int main()
{
    int array[] = {0, 1, 2, 3};
    int* ptr = array;

    // 2番目
    ptr += 2;
    std::cout << *ptr << std::endl;

    // 3番目
    ++ptr;
    std::cout << *ptr << std::endl;

    // 1番目
    ptr -= 2;
    std::cout << *ptr << std::endl;

    // 0番目
    --ptr;
    std::cout << *ptr << std::endl;
}
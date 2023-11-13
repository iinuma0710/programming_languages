#include <iostream>

int main()
{
    int* ptr = 0;
    std::cout << ptr << std::endl;

    ptr = nullptr;
    std::cout << ptr << std::endl;
}
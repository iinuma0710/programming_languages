#include <iostream>

int main()
{
    int array[10] = {};
    std::size_t length = sizeof(array) / sizeof(int);
    std::cout << "array[" << length << "]" << std::endl;
}
#include <iostream>

int main()
{
    int array[10] = {};
    std::size_t length = sizeof(array) / sizeof(array[0]);
    std::cout << "array[" << length << "]" << std::endl;
}
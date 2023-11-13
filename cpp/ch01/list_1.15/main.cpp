#include <iostream>

int main()
{
    int* ptr = nullptr;

    if (ptr == nullptr)
    {
        std::cout << "ptr はヌルポインタです" << std::endl;
    }
    else
    {
        *ptr = 42;
    }
}
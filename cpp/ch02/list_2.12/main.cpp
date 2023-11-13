#include <iostream>

int one()
{
    return 1;
}

int main()
{
    auto i = one();
    decltype(i) j;
    j = 42.195;
    std::cout << j << std::endl;
}
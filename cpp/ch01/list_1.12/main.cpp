#include <iostream>

void nochange(int i)
{
    i = 42;
}

void set42(int* pi)
{
    *pi = 42;
}

int main()
{
    int i = 0;

    nochange(i);
    std::cout << i << std::endl;

    set42(&i);
    std::cout << i << std::endl;
}
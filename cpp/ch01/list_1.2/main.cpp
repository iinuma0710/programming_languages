#include <iostream>

void hello_world()
{
    std::cout << "Hello, world" << std::endl;
}

void show_sum(int a, int b)
{
    int c = a + b;
    std::cout << c << std::endl;
}

int main()
{
    hello_world();
    show_sum(1, 2);
}
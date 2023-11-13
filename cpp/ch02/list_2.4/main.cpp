#include <iostream>

union U
{
    int a;
    int b;
    int c;
};

int main()
{
    U u;

    std::cout << "u.a のアドレス: " << &u.a << std::endl;
    std::cout << "u.b のアドレス: " << &u.b << std::endl;
    std::cout << "u.c のアドレス: " << &u.c << std::endl;
}
#include <iostream>

struct S
{
    int a;
    int b;
    int c;
};

int main()
{
    S s;

    std::cout << "s.a のアドレス: " << &s.a << std::endl;
    std::cout << "s.b のアドレス: " << &s.b << std::endl;
    std::cout << "s.c のアドレス: " << &s.c << std::endl;
}
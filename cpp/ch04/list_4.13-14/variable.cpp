#include <iostream>

int value = 42;

void show_extern_variable()
{
    std::cout << "extern 変数のアドレス: " << &value << std::endl;
    std::cout << "extern 変数の値: " << value << std::endl;
}
#include <iostream>

extern int value;   // extern 宣言

void show_extern_variable();

int main()
{
    std::cout << "main: extern 変数のアドレス: " << &value << std::endl;
    std::cout << "main: extern 変数の値: " << value << std::endl;

    value = 0;
    show_extern_variable();
}
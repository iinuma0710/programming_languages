#include <iostream>

int main()
{
    int value = 42;
    std::cout << "value のアドレスは " << &value << "、値は " << value << std::endl;

    int& reference = value;
    std::cout << "refelence のアドレスは " << &reference << "、値は " << reference << std::endl;

    // 参照元のデータを書き換えられる
    reference = 0;
    std::cout << "value のアドレスは " << &value << "、値は " << value << std::endl;
}
#include <iostream>

int main()
{
    int a = 0;

    auto lambda = [a]() mutable
    {
        a = 42;
        std::cout << "キャプチャした変数: " << a << std::endl;
    };
    lambda();

    // ラムダ式ないで値を変更しても、元の変数は影響を受けない
    std::cout << "元の変数: " << a << std::endl;
}
#include <iostream>

int main()
{
    int a = 0;

    auto lambda = [a]()
    {
        // 変数 a のコピーがラムダ式内部に作られる
        std::cout << a << std::endl;
    };
    lambda();

    // ラムダ式にはコピーが保持されているので、元の変数の変更の影響を受けない
    a = 42;
    lambda();
}
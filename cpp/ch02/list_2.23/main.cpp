#include <iostream>

int main()
{
    int a = 0;

    // aを参照できるキャプチャ
    auto lambda = [&a]()
    {
        std::cout << "キャプチャした変数: " << a << std::endl;
        // 参照でキャプチャした変数を変更可能
        ++a;
    };
    lambda();

    // 元の変数も影響を受ける
    std::cout << "元の変数: " << a << std::endl;

    // 元の変数を変更すると、ラムダ式の中の値も変わる
    a = 42;
    lambda();
}
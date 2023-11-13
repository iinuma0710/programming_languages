#include <iostream>

int main()
{
    int a = 0;
    float b = 3.14f;

    // ラムダ式内部で使われている変数だけが自動的にキャプチャされる
    auto lambda = [=]()
    {
        std::cout << a << std::endl;
    };
    lambda();
}
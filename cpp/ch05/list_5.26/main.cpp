#include <iostream>

int identity(int v)
{
    return v;
}

int square(int v)
{
    return v * v;
}

int main()
{
    // 関数ポインタを宣言し、identity で初期化する
    int (*func)(int) = &identity;

    // 関数ポインタを経由して idenntity を呼び出す
    std::cout << "func(4): " << func(4) << std::endl;

    // 関数ポインタに square のアドレスを代入
    func = &square;

    // 関数ポインタを経由して square を呼び出す
    std::cout << "func(4): " << func(4) << std::endl;
}
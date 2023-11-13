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
    // 関数リファレンスを宣言し、identity で初期化する
    int (&func)(int) = identity;

    // 関数リファレンスを経由して idenntity を呼び出す
    std::cout << "func(4): " << func(4) << std::endl;

    // 関数リファレンスの参照先の変更はできない
    // func = square;
}
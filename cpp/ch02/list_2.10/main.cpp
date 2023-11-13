#include <iostream>

int one()
{
    return 1;
}

int main()
{
    auto d = 3.14;  // double 型に推論される
    d = 2.71f;      // float 型のリテラルなので格納できる
    std::cout << d << std::endl;

    auto i = one(); // 関数の返り値の型から int 型に推論される
    i = 42.195;     // double 型から暗黙の型変換が行われる
    std::cout << i << std::endl;
}
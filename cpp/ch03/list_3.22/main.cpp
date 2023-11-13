#include <iostream>

class S
{
public:
    static int num; // static メンバ変数の宣言
};

int S::num = 123;   // static メンバ変数の定義と初期化

int main()
{
    std::cout << S::num << std::endl;

    S::num = 456;

    // インスタンスを通してアクセスもできる
    S s;
    std::cout << s.num << std::endl;
}
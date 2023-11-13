#include <iostream>

union U
{
    int a;
    int b;
    int c;
};

int main()
{
    U u = { 42 };   // 先頭のメンバで初期化する

    // u.b と u.a は同じ場所にあるので値も同じ
    std::cout << "u.b の値: " << u.b << std::endl;

    // u.c への変更で他のメンバ変数も変更される
    u.c = 1024;
    std::cout << "u.a の値: " << u.a << std::endl;
}
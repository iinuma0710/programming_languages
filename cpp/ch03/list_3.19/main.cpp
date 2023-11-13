#include <iostream>

union U
{
    // デフォルトは public
    float f;

private:
    int i;

public:
    U();
    int get_i() const;
};

// コンストラクタでは先頭以外のメンバ変数で初期化できる
U::U() : i(0xdeadbeef)
{
    std::cout << "&f: " << &f << std::endl << "&i: " << &i << std::endl;
}

int U::get_i() const
{
    // 共用体でも this が使える 
    return this->i;
}

int main()
{
    U u;    // デフォルトコンストラクタが int 型で初期化
    std::cout <<std::hex << u.get_i() << std::endl;
    
    u.f = 2.71828f;
    std::cout <<std::hex << u.get_i() << std::endl;
}

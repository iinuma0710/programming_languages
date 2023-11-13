#include <iostream>

class A
{
    int i;

public:
    // コンストラクタの宣言と定義
    A() : i (0) {}

    // メンバ関数の宣言と定義
    void set_i(int i) { this->i = i; }

    // const メンバ関数の定義
    void show() const
    {
        std::cout << i << std::endl;
    }
};

int main()
{
    A a;
    a.show();
    a.set_i(123);
    a.show();
}
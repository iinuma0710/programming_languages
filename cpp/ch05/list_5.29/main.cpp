#include <iostream>

class C
{
    int a;

public:

    explicit C(int a) : a{a} {}

    // const メンバ関数なのでメンバ変数は変更できない
    void copy_and_set(int value) const
    {
        std::cout << "copy_and_set: a == " << a << std::endl;

        // this が指し示す先のインスタンスを丸ごとコピー
        [*this, value]() mutable
        {
            std::cout << "lambda: a == " << a << std::endl;
            a = value;  // コピーされたインスタンスの a を変更
            std::cout << "lambda: a == " << a << std::endl;
        }();

        std::cout << "copy_and_set: a == " << a << std::endl;
    }
};

int main()
{
    C c{42};
    c.copy_and_set(0);
}
#include <iostream>

int foo(int value)
{
    // 何か複雑な処理
    std::cout << "foo: " << value << std::endl;
    return value;
}

bool is_even(int value)
{
    return value % 2 == 0;
}

bool is_zero(int value)
{
    return value == 0;
}

int main()
{
    // 複雑な foo() が2回呼ばれてしまう
    if (is_even(foo(42)) && !is_zero(foo(42)))
    {
        std::cout << "foo(42) はゼロではない偶数を返しました" << std::endl;
    }
}
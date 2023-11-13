#include <iostream>

int main()
{
    int i = 42;

    {
        int i = 72; // スコープが異なるので同名のローカル変数を作成可能

        // 今いるスコープから最も内側にある変数が使われる
        std::cout << "inner: " << &i << ": " << i << std::endl;

        i = 0;
    }

    // 外側の変数が参照される
    std::cout << "inner: " << &i << ": " << i << std::endl;
}
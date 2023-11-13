#include <iostream>

void show(int& v)
{
    std::cout << "参照: " << v << std::endl;
}

void show(int&& v)  // 右辺値参照で受け取るオーバロード
{
    std::cout << "右辺値参照: " << v << std::endl;
}

int main()
{
    int v = 1;
    show(v);
    show(42);
}
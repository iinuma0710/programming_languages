#include <iostream>

int x;

// 参照を返す関数
int& get_x()
{
    // 参照を返す場合でも特別なことはしなくても良い
    return x;
}

int main()
{
    x = 10;
    int& y = get_x();
    y = 100;
    std::cout << x << std::endl;
}
#include <iostream>

struct vector2d
{
    int x;
    int y;
};

// 整数用のオーバロード
int add(int left, int right)
{
    return left + right;
}

// 浮動小数点数用のオーバロード
double add(double left, double right)
{
    return left + right;
}

// 2次元ベクトル用のオーバロード
vector2d add(vector2d left, vector2d right)
{
    vector2d v;
    v.x = left.x + right.x;
    v.y = left.x + right.y;
    return v;
}

int main()
{
    int integer = add(1,2);
    std::cout << integer << std::endl;

    double floating = add(3.14, 42.195);
    std::cout << floating <<std:: endl;

    vector2d v = { 1, 2 };
    vector2d u = { -3, 4 };
    vector2d w = add(v, u);
    std::cout << w.x << ", " << w.y << std:: endl;
}
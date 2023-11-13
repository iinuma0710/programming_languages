#include <iostream>

class Triangle
{
    float height;
    float width;

public:
    explicit Triangle(float height, float width);

    float area() const;
};

Triangle::Triangle(float height, float width)
    : height(height), width(width) {}

float Triangle::area() const
{
    return height * width / 2;
}

int main()
{
    // コンストラクタへの引数はカンマ区切りで渡す
    Triangle* tri = new Triangle{10.5f, 5.0f};

    std::cout << "三角形の面積: " << tri->area() << std::endl;

    delete tri;
}
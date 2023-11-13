#include <iostream>

enum class Category
{
    Value1, // 明示的な指定がない限り先頭は0
    Value2, // 値の指定がなければ直前の値＋1
    Value3 = 100,   // 値の指定も可能
    Value4, // 直前の値＋1
};

int main()
{
    // Value3 で初期化
    Category cat = Category::Value3;

    // 列挙体の値に対応した整数を取得
    std::cout << static_cast<int>(cat) << std::endl;
}
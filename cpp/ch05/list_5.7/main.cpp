#include <vector>
#include <iostream>

int main()
{
    // 空の動的配列
    std::vector<int> empty;
    std::cout << "empty.size(): " << empty.size() << std::endl;

    // 初期化済みの動的配列
    std::vector<int> array = {10, 20, 30, 40, 50};
    std::cout << "array.size(): " << array.size() << std::endl;

    // 範囲 for 文で走査
    for (int e : array)
    {
        std::cout << e << std::endl;
    }
}
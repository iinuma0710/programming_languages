#include <vector>
#include <iostream>

int main()
{
    std::vector<int> list;

    list.push_back(42); // 末尾に要素を追加
    list.push_back(0);  // 末尾に要素を追加

    for (int e : list)
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    list.pop_back();        // 末尾の要素を削除
    list.push_back(-10);    // 末尾に要素を追加
    
    for (int e : list)
    {
        std::cout << e << std::endl;
    }
}
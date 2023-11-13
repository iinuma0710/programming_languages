#include <iostream>
#include <string>

// 関数の前方宣言
std::string get_message();

int main()
{
    auto msg = get_message();

    std::cout << msg << std::endl;
}

// 関数の定義
std::string get_message()
{
    return "Hello, forward declaration";
}
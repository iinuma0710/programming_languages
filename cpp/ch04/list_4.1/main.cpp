#include <iostream>

int main()
{
    // ソースファイルの名前
    std::cout << "__FILE__: " << __FILE__ << std::endl;
    // 行番号
    std::cout << "__LINE__: " << __LINE__ << std::endl;
    // 現在の関数名
    std::cout << "__func__: " << __func__ << std::endl;
    // C++ のバージョン
    std::cout << "__cplusplus__: " << __cplusplus << std::endl;

    int line = __LINE__;
    std::cout << "line: " << line << ", __LINE__: " << __LINE__ << std::endl;
}
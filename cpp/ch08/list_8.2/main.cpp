#include <iostream>

int main()
{
    auto dephault = std::cout.flags();  // デフォルトのフラグを取得

    std::cout.setf(std::ios::scientific);

    // basefield をクリアして16進のフラグをセット
    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::cout << 123.456f << std::endl;
    std::cout << 123456 << std::endl;

    // デフォルトにリセット
    std::cout.flags(dephault);

    std::cout << 123.456f << std::endl;
    std::cout << 123456 << std::endl;
}
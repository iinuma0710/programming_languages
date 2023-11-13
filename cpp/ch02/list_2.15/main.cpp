#include <iostream>
#include <string>

int main()
{
    std::string s;

    std::cout << "文字列を入力して下さい> ";
    std::cin >> s;

    std::cout << "入力された文字列は \"" << s << "\" です" << std::endl;
}
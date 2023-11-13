#include <iostream>

int main()
{
    char hello[] = "Hello";
    char array[6] = {'a', 'r', 'r'};
    array[3] = 'a';
    array[4] = 'y';
    array[5] = '\0'; // 文字列は必ずヌル文字で終わる

    std::cout << hello << ", " << array << std::endl;
}
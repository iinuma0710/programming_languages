#include <iostream>

int main()
{
    int a = 2;
    switch (a + 1)
    {
        case 1:
            std::cout << "a + 1 は 1 です" << std::endl;
            break;
        
        case 2:
            std::cout << "a + 1 は 2 です" << std::endl;
            break;

        case 3:
            std::cout << "a + 1 は 3 です" << std::endl;
            break;
        
        default:
            std::cout << "a + 1 は 1 でも 2 でも 3 でもありません" << std::endl;
            break;
    }
}
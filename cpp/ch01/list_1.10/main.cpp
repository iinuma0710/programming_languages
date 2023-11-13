#include <iostream>

int main()
{
    int a = 2;
    switch (a)
    {
        case 1:
        case 2:
        case 3:
            std::cout << "a は 1 か 2 か 3 です" << std::endl;
            return 0;
    }

    std::cout << "残りの処理" << std::endl;
}
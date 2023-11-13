#include <iostream>

int main()
{
    int value[] = {-20, 10, 5, -40, 0, 10, -30};

    for (int i = 0; i < 7; ++i)
    {
        if (value[i] < 0)
        {
            std::cout << "continue" << std::endl;
            continue;
        }

        if (value[i] == 0)
        {
            std::cout << "break" << std::endl;
            break;
        }

        std::cout << "elem = " << value[i] << std::endl;
    }

    std::cout << "ループの終了" << std::endl;
}
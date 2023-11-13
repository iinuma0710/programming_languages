#include <iostream>

class S
{
public:
    int answer = 42;
    float pi{ 3.14159265f };
};

int main()
{
    S s;

    std::cout << "s.answer: " << s.answer << std::endl;
    std::cout << "s.pi: " << s.pi << std::endl;
}
#include <iostream>

class Integer
{
    int value;

public:

    Integer(int value) : value{value} {}

    bool operator!() const;
    bool operator&&(const Integer& rhs) const;
    bool operator||(const Integer& rhs) const;
};

bool Integer::operator!() const
{
    return value == 0;
}

bool Integer::operator&&(const Integer& rhs) const
{
    return value && rhs.value;
}

bool Integer::operator||(const Integer& rhs) const
{
    return value || rhs.value;
}

int main()
{
    Integer x = 10;
    Integer y = 3;
    Integer z = 0;

    if (x && y)
    {
        std::cout << "x と y はどちらも 0 ではない" << std::endl;
    }
    if (z || x)
    {
        std::cout << "z と x の少なくともどちらかは 0 ではない" << std::endl;
    }
    if (!z)
    {
        std::cout << "z は 0" <<std::endl;
    }
}
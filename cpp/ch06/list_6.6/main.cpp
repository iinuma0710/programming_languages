#include <iostream>

class Integer
{
    int value;

public:

    Integer(int value) : value{value} {}

    bool operator==(const Integer& rhs) const;
    bool operator!=(const Integer& rhs) const;
    bool operator<(const Integer& rhs) const;
    bool operator>(const Integer& rhs) const;
    bool operator<=(const Integer& rhs) const;
    bool operator>=(const Integer& rhs) const;
};

bool Integer::operator==(const Integer& rhs) const
{
    return value == rhs.value;
}

bool Integer::operator!=(const Integer& rhs) const
{
    // == を呼び出してその否定を返す
    return !(*this == rhs);
}

bool Integer::operator<(const Integer& rhs) const
{
    return value < rhs.value;
}

bool Integer::operator>(const Integer& rhs) const
{
    // 左右を入れ替えて < を呼び出す
    return rhs < *this;
}

bool Integer::operator<=(const Integer& rhs) const
{
    // 大なりの否定
    return !(rhs < *this);
}

bool Integer::operator>=(const Integer& rhs) const
{
    return rhs <= *this;
}

int main()
{
    Integer x = 10;
    Integer y = 3;

    if (x != y)
    {
        std::cout << "x != y は true" << std::endl;
    }
    else
    {
        std::cout << "x != y は false" << std::endl;
    }

    if (y >= x)
    {
        std::cout << "y >= x は true" << std::endl;
    }
    else
    {
        std::cout << "y >= x は false" << std::endl;
    }
}
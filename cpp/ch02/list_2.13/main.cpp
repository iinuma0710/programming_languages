#include <iostream>

class data
{
public:
    // クラス内で使う型に別名をつける
    using integer = int;

    // クラス内では直接使える
    integer get_value();
    void set_value(integer new_value);

private:
    integer value;
};

// クラス外ではスコープ解決演算子を使う
data::integer data::get_value()
{
    return value;
}

// メンバ関数内ではスコープ解決演算子不要
void data::set_value(integer new_value)
{
    integer tmp = new_value;
    value = tmp;
}

int main()
{
    data d;

    // ネストした型名に別名をつけても良い
    using integer = data::integer;
    integer value = 42;
    d.set_value(value);
    std::cout << d.get_value() <<std::endl;
}
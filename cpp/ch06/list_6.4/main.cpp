#include <iostream>

class Integer
{
    int value;

public:

    Integer(int value) : value{value} {}

    Integer operator++();   // 前置インクリメント演算子
    Integer operator--();   // 前置デクリメント演算子

    Integer operator++(int);    // 後置インクリメント演算子
    Integer operator--(int);    // 後置デクリメント演算子

    void show() const;
};

Integer Integer::operator++()
{
    // メンバ関数の値を変更してから自分自身の参照を返す
    ++value;
    return *this;
}

Integer Integer::operator--()
{
    --value;
    return *this;
}

Integer Integer::operator++(int)
{
    // 変更前の値を返すため先に自分自身のコピーを作っておく
    auto tmp = *this;
    ++(*this);  // 前置の呼び出し
    return tmp;
}

Integer Integer::operator--(int)
{
    auto tmp = *this;
    --(*this);
    return tmp;
}

void Integer::show() const
{
    std::cout << "Integer.value = " << value << std::endl;
}

int main()
{
    Integer x = 10;
    
    ++x;
    x.show();

    x++;
    x.show();

    --x;
    x.show();

    x--;
    x.show();
}
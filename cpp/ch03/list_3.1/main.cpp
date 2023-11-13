#include <iostream>

class product
{
    int id;

public:
    int get_id() const;
    void set_id(int new_id);
};

// getter は const メンバ関数の方が都合が良い
int product::get_id() const
{
    return id;
}

// setter は const メンバ関数にしない
void product::set_id(int new_id)
{
    id = new_id;
}

int main()
{
    const product cp{};

    // const なインスタンスに対して const メンバ関数を呼び出せる
    std::cout << cp.get_id() << std::endl;
}
#include <iostream>

class S
{
    static int count;

public:
    S();
    ~S();

    void show_count() const;
};

int S::count = 0;

S::S()
{
    // インスタンスの生成でインクリメント
    ++count;
}

S::~S()
{
    // インスタンスの破棄でデクリメント
    --count;
}

void S::show_count() const
{
    std::cout << "S::count: " << count << std::endl;
}

void function()
{
    S a;
    a.show_count();
}

int main()
{
    S a;
    a.show_count();
    function();
    a.show_count();
}
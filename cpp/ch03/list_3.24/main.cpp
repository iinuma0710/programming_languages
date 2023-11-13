#include <iostream>

class S
{
    static int count;

public:
    S();
    ~S();

    static void show_count();
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

void S::show_count()
{
    std::cout << "S::count: " << count << std::endl;
}

int main()
{
    S::show_count();
    S a;
    a.show_count();
}
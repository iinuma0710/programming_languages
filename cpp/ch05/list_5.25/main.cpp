#include <iostream>
#include <utility>

class home
{
    int* m_land;    // 土地

public:
    
    explicit home(std::size_t size) : m_land{new int[size]} {}
    ~home() { delete [] m_land; }
    home(home&& other);
    int* land() const {return m_land; }
};

home::home(home&& other) : m_land{other.m_land} // 初期化のタイミングでムーブ元のポインタをコピー
{
    // ムーブ元のポインタを空にする
    // このポインタの所有権はこのオブジェクトのものになる
    other.m_land = nullptr;
}

int main()
{
    home A{100};

    std::cout << "A の土地のアドレス: " << A.land() << std::endl;

    // A から B に所有権を移動
    home B{std::move(A)};

    std::cout << "B の土地のアドレス: " << B.land() << std::endl;
    std::cout << "移動後の A の土地のアドレス: " << A.land() << std::endl;
}
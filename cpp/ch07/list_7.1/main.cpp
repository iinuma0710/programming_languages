#include <iostream>

class Base
{
// 被保護メンバ
protected:
    void protected_member()
    {
        std::cout << "Base::protected_member()" << std::endl;
    }
};

class Derived : public Base
{
public:
    void member_test();
};

void Derived::member_test()
{
    // 基底クラスの被保護メンバにアクセスできる
    protected_member();
}

int main()
{
    Derived derived;

    // 派生クラスのオブジェクトを通して被保護メンバにアクセスすることはできない
    // derived.protected_member();

    // 高階メンバを通してアクセスできる
    derived.member_test();
}
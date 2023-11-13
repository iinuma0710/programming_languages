#include <iostream>
#include <string>

class person
{
    std::string m_name;
    int         m_age;

    person(int age);

public:
    person();
    person(std::string name, int age);

    // コピーコンストラクタ
    person(const person& other);

    void set_name(std::string name);
    void set_age(int age);

    std::string name() const;
    int         age() const;
};

// 共通の初期化処理が記述されたコンストラクタ
person::person(int age) : m_age(age)
{
    std::cout << "共通コンストラクタ呼び出し" << std::endl;
}

person::person() : person(-1)
{
    std::cout << "引数なしコンストラクター呼び出し" << std::endl;
}

person::person(std::string name, int age) : person(age)
{
    std::cout << "引数ありコンストラクター呼び出し" << std::endl;
    set_name(name);
}

// コピーコンストラクタ
person::person(const person& other)
{
    std::cout << "コピーコンストラクタの呼び出し" << std::endl;

    set_name(other.name());
    set_age(other.age());
}

void person::set_name(std::string name)
{
    m_name = name;
}

void person::set_age(int age)
{
    m_age = age;
}

std::string person::name() const
{
    return m_name;
}

int person::age() const
{
    return m_age;
}

int main()
{
    person alice("alice", 15);
    person copy(alice);

    std::cout << copy.name() << std::endl;
    std::cout << alice.name() << std::endl;
}
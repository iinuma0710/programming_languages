#include <iostream>
#include <vector>
#include <string>

class Object
{
    std::string name;

public:

    Object() : name("NO NAME") {}
    explicit Object(std::string name) : name(name) {}
    ~Object();

    void show_name() const;
};

Object::~Object()
{
    std::cout << "Object のデストラクタ" << std::endl;
}

void Object::show_name() const
{
    std::cout << "Object name: " << name << std::endl;
}

int main()
{
    Object* obj = new Object[10]
    {
        Object{"first"},
        Object{"second"},
        // これ以降の要素はデフォルトコンストラクタで初期化
    };

    obj[0].show_name();
    obj[1].show_name();
    obj[2].show_name();

    // 配列の delete では、各要素のデストラクタが呼ばれる
    delete [] obj;
}
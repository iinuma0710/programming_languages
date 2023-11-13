#include <iostream>
#include <string>

class Object
{
    std::string name;

public:

    Object(std::string name);
    const std::string& get_name() const;
};

Object::Object(std::string name) : name{name}
{
    // 文字列をメンバ変数の name にコピー
}

const std::string& Object::get_name() const
{
    return name;    // name を参照で返す
}

int main()
{
    Object obj{"とても大きなオブジェクト"};

    // メンバ変数の参照を取得すればコピーが起きないので高速
    const std::string& name = obj.get_name();
    std::cout << name <<std::endl;
}
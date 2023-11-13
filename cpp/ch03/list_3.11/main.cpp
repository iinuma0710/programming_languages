#include <iostream>
#include <string>

class Book
{
    std::string title = "";
    int page = 0;

public:
    Book();
    explicit Book(std::string title, int page);

    void show() const;
};

// メンバ初期化リストで省略したメンバ変数は NSDMI のデフォルト値で初期化される
Book::Book() : title("untitled") {}

// メンバ初期化リストで与えた初期値が使われる
Book::Book(std::string title, int page) : title(title), page(page) {}

void Book::show() const
{
    std::cout << title << " " << page << "ページ" <<std::endl;
}

int main()
{
    Book nsdmi;
    nsdmi.show();

    Book old_edition{ "独習C++ 第4版", 568 };
    old_edition.show();
}
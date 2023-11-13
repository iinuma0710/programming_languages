#include <iostream>

struct product
{
    int id;     // 商品 ID
    int price;  // 単価
    int stock;  // 在庫数
};

int main()
{
    product pen;

    // ドット演算子でメンバ変数に情報を格納
    pen.id = 0;
    pen.price = 100;
    pen.stock = 200;

    product* ptr = &pen;    // 構造体変数へのポインタ

    // アロー演算子でメンバ変数を取得
    std::cout << "商品ID: " << ptr->id << std::endl;
    std::cout << "単価: " << ptr->price << std::endl;
    std::cout << "在庫数: " << ptr->stock << std::endl;
}
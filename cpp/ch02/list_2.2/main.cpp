#include <iostream>

struct product
{
    int id;     // 商品 ID
    int price;  // 単価
    int stock;  // 在庫数
};

void show_product(product product)
{
    std::cout << "商品ID: " << product.id << std::endl;
    std::cout << "単価: " << product.price << std::endl;
    std::cout << "在庫数: " << product.stock << std::endl;
}

int main()
{
    product pen =
    {
        0,      // 商品ID
        100,    // 単価
        200,    // 在庫数
    };

    show_product(pen);
}
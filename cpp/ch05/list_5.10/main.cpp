#include <iostream>

int* local()
{
    int i = 42;
    return &i;  // ダングリングポインタになるので注意
}

int* dyn_alloc()
{
    // 動的確保されたオブジェクトはスコープを抜けても破棄されない
    int* ptr = new int;
    *ptr = 42;
    return ptr;
}

int main()
{
    // local() から返ってくるポインタはダングリングポインタ
    // int* l = local()
    // std::cout << *l << std::endl;

    // 動的確保したオブジェクトはアクセス可能
    int* d = dyn_alloc();
    std::cout << *d << std::endl;
    
    // 動的確保されたオブジェクトは必ず手動で破棄する
    delete d;
}
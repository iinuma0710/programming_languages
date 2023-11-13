#include <iostream>

int* dangling_pointer()
{
    int i = 0;
    return &i;  // ダングリングポインタになる
}

int main()
{
    int* p = dangling_pointer();
    *p = 42;    // 非常に危険
}
#include <iostream>

// #define PLUS(a, b) (a + b)  // 加算を行う関数形式マクロ
#define HOGE

int main()
{
#if (defined(HOGE) + 0)
    std::cout << "(defined(HOGE) + 0) は true です" <<std::endl;
#else
    std::cout << "(defined(HOGE) + 0) は false です" <<std::endl;
#endif
}

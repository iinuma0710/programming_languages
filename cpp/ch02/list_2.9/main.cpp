#include <iostream>

int main()
{
    int value = 42;
    int other = 0;
    int* pointer = &value;
    int& reference = value;

    std::cout << "value のアドレスは " << &value << "、値は " << value << std::endl;
    std::cout << "other のアドレスは " << &other << "、値は " << other << std::endl;
    std::cout << "pointer の持つアドレスは " << pointer << "、値は " << *pointer << std::endl;
    std::cout << "reference のアドレスは " << &reference << "、値は " << reference << std::endl;

    pointer = &other;   // ポインタの持つアドレスを other のアドレスに変更
    reference = other;  // 参照先を other に変えたつもり
    
    std::cout << std::endl;
    std::cout << "value のアドレスは " << &value << "、値は " << value << std::endl;
    std::cout << "other のアドレスは " << &other << "、値は " << other << std::endl;
    std::cout << "pointer の持つアドレスは " << pointer << "、値は " << *pointer << std::endl;
    std::cout << "reference のアドレスは " << &reference << "、値は " << reference << std::endl;
}
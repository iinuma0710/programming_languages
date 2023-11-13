#include <iostream>

class heavy_class
{
    int m_value;

    // mutable を付けると非 const メンバ関数からも変更できる
    mutable int m_cache;
    mutable bool m_cache_valid;

public:
    int generate() const;
    void set(int value);
    int get() const;
};

int heavy_class::generate() const
{
    std::cout << "とても重いデータを生成する関数" << std::endl;
    return m_value;
}

void heavy_class::set(int value)
{
    // 処理が重い場合、必要になるまでデータを生成しないこともある
    m_cache_valid = false;
    m_value = value;
}

int heavy_class::get() const
{
    if (m_cache_valid) { return m_cache; }

    // mutable なメンバ変数は変更できる
    m_cache = generate();
    m_cache_valid = true;

    return m_cache;
}

int main()
{
    heavy_class heavy_object;
    
    heavy_object.set(100);
    std::cout << heavy_object.get() << std::endl;

    // generate は呼ばれず、キャッシュが返される
    std::cout << heavy_object.get() << std::endl;

    heavy_object.set(200);
    std::cout << heavy_object.get() << std::endl;

    // generate は呼ばれず、キャッシュが返される
    std::cout << heavy_object.get() << std::endl;
}
#include <iostream>

class vector4d
{
private:
    
    float x, y, z, w;

public:

    vector4d(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}

    friend vector4d add(const vector4d& lhs, const vector4d& rhs);
};

vector4d add(const vector4d& lhs, const vector4d& rhs)
{
    vector4d ret
    {
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
        lhs.w + rhs.w,
    };
    return ret;
}

class vector3d
{
private:
    
    float x, y, z;

public:

    vector3d(float x, float y, float z) : x{x}, y{y}, z{z} {}
    // vector3d を vector4d に変換する変換関数
    operator vector4d() const;
};

vector3d::operator vector4d() const
{
    vector4d ret{x, y, z, 0.0f};
    return ret;
}

int main()
{
    vector3d v1{1, 2, 3}, v2{0, 1, 0};

    vector4d a = v1;            // vector3d -> vector4d に変換される
    vector4d b = add(v1, v2);   // vector4d のフレンド関数が呼ばれる
}
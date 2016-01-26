#include "Vec2.h"

namespace PongGame
{
Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 operator*(const Vec2& v, const float n)
{
    return Vec2(v.x * n, v.y * n);
}

Vec2 Vec2::operator*(const float n)
{
    Vec2 ret(*this);
    ret.x *= n;
    ret.y *= n;
    return ret;
}

Vec2 Vec2::operator-()
{
    Vec2 ret(*this);
    ret.x = -ret.x;
    ret.y = -ret.y;
    return ret;
}

Vec2 Vec2::operator-(const Vec2& v)
{
    Vec2 ret(*this);
    ret.x -= v.x;
    ret.y -= v.y;
    return ret;
}

Vec2& Vec2::operator+=(const Vec2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2& v)
{
    Vec2 ret(*this);
    ret.x += v.x;
    ret.y += v.y;
    return ret;
}

float Vec2::len() const
{
    return std::sqrt(len2());
}

float Vec2::len2() const
{
    return x*x + y*y;
}

float Vec2::dot(const Vec2& v1, const  Vec2& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vec2 Vec2::normalize(const Vec2& v)
{
    if (v.x == 0.0f && v.y == 0.0f)
        return Vec2(v);
    float len = v.len();
    return Vec2(v.x / len, v.y / len);
}
}
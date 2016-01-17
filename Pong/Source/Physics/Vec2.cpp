#include "Vec2.h"

namespace PongGame
{
Vec2::Vec2(float x, float y) : x(x), y(y) {}

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

float Vec2::len()
{
    return sqrt(len2());
}

float Vec2::len2()
{
    return x*x + y*y;
}
}
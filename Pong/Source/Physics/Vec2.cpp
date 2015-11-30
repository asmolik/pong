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

Vec2& Vec2::operator+=(const Vec2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
}
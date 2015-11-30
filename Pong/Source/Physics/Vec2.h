#pragma once

#include <vector>
#include <memory>

namespace PongGame
{
struct Vec2
{
    float x;
    float y;

    Vec2(float x = 0.0f, float y = 0.0f);

    Vec2 operator*(const float n);
    Vec2& operator+=(const Vec2& v);
};
}
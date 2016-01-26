#pragma once

#include <cmath>

namespace PongGame
{
struct Vec2
{
    float x;
    float y;

    Vec2(float x = 0.0f, float y = 0.0f);

    friend Vec2 operator*(const Vec2& v, const float n);
    Vec2 operator*(const float n);
    Vec2 operator-();
    Vec2 operator-(const Vec2& v);
    Vec2& operator+=(const Vec2& v);
    Vec2 operator+(const Vec2& v);

    // Length of the vector
    float len() const;
    // Length sqauared
    float len2() const;

    static float dot(const Vec2& v1, const Vec2& v2);
    static Vec2 normalize(const Vec2& v);
};
}
#pragma once

#include "CollisionShape.h"
#include "ShapeVisitor.h"

namespace PongGame
{
class Rectangle : public CollisionShape
{
public:
    float a, b;
    Vec2 normal;

    Rectangle(GameObject& object, float a, float b, const Vec2& normal);
    virtual ~Rectangle();
    virtual void accept(ShapeVisitor& v);
};
}
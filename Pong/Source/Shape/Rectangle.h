#pragma once

#include "CollisionShape.h"
#include "ShapeVisitor.h"

namespace PongGame
{
class Rectangle : public CollisionShape
{
public:
    float a, b;

    Rectangle(PositionComponent& position, float a, float b);
    virtual ~Rectangle();
    virtual void accept(ShapeVisitor& v) = 0;
};
}
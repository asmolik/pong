#pragma once

#include "CollisionShape.h"
#include "ShapeVisitor.h"

namespace PongGame
{
class Circle : public CollisionShape
{
public:
    float radius;

    Circle(PositionComponent& position, float radius);
    virtual ~Circle();
    virtual void accept(ShapeVisitor& v);
};
}
#pragma once

#include "CollisionShape.h"
#include "ShapeVisitor.h"

namespace PongGame
{
class Line : public CollisionShape
{
public:
    Vec2 normal;

    Line(GameObject& object, Vec2& normal);
    virtual ~Line();
    virtual void accept(ShapeVisitor& v);
};
}
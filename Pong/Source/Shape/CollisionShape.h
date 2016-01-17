#pragma once

#include "Component/PositionComponent.h"
#include "ShapeVisitor.h"

namespace PongGame
{
class PositionComponent;
class CollisionShape
{
public:
    PositionComponent& position;

    CollisionShape(PositionComponent& position);
    virtual ~CollisionShape();
    virtual void accept(ShapeVisitor& v) = 0;
};
}
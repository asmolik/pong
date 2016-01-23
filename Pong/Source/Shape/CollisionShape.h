#pragma once

#include "Object/GameObject.h"
#include "Component/PositionComponent.h"
#include "ShapeVisitor.h"

namespace PongGame
{
struct PositionComponent;

class CollisionShape
{
public:
    // Object owning this shape.
    GameObject& object;
    // Position of the object owning this shape.
    PositionComponent& position;

    CollisionShape(GameObject& position);
    virtual ~CollisionShape();
    virtual void accept(ShapeVisitor& v) = 0;
};
}
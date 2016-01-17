#pragma once

#include <memory>
#include "Component/PositionComponent.h"
#include "ShapeVisitor.h"
#include "CollisionShape.h"
#include "CircleVisitor.h"
#include "RectangleVisitor.h"

namespace PongGame
{
// Visitor resolving collisions between shapes.
class CollisionVisitor : public ShapeVisitor
{
private:
    CollisionShape& shape;
    std::unique_ptr<Contact> value;
public:
    CollisionVisitor(CollisionShape& shape);
    virtual ~CollisionVisitor();

    virtual void visit(Circle& shape);
    virtual void visit(Line& shape);
    virtual void visit(Rectangle& shape);
    virtual std::unique_ptr<Contact> get();
};
}
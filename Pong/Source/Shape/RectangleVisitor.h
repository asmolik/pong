#pragma once

#include "ShapeVisitor.h"
#include "CollisionShape.h"
#include "Circle.h"
#include "Rectangle.h"

namespace PongGame
{
class CollisionVisitor : public ShapeVisitor
{
private:
    CollisionShape& shape;
    Contact value;
public:
    CollisionVisitor(CollisionShape& shape);
    virtual ~CollisionVisitor();

    virtual void visit(Circle& shape);
    virtual void visit(Line& shape);
    virtual void visit(Rectangle& shape);
};
}
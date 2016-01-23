#pragma once

#include <memory>
#include "ShapeVisitor.h"
#include "CollisionShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Collision/Contact.h"
#include "Collision/RectangleCircle.h"
#include "Collision/CircleLine.h"

namespace PongGame
{
class CircleVisitor : public ShapeVisitor
{
private:
    Circle& shape;
    std::unique_ptr<Contact> value;
public:
    CircleVisitor(Circle& shape);
    virtual ~CircleVisitor();

    virtual void visit(Circle& shape);
    virtual void visit(Line& shape);
    virtual void visit(Rectangle& shape);

    std::unique_ptr<Contact> get();
};
}
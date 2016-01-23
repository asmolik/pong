#pragma once

#include <memory>
#include "ShapeVisitor.h"
#include "CollisionShape.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Collision/Contact.h"
#include "Collision/CircleLine.h"

namespace PongGame
{
class LineVisitor : public ShapeVisitor
{
private:
    Line& shape;
    std::unique_ptr<Contact> value;
public:
    LineVisitor(Line& shape);
    virtual ~LineVisitor();

    virtual void visit(Circle& shape);
    virtual void visit(Line& shape);
    virtual void visit(Rectangle& shape);

    std::unique_ptr<Contact> get();
};
}
#pragma once

#include <memory>
#include "ShapeVisitor.h"
#include "CollisionShape.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Collision/Contact.h"
#include "Collision/RectangleCircle.h"

namespace PongGame
{
class RectangleVisitor : public ShapeVisitor
{
private:
    Rectangle& shape;
    std::unique_ptr<Contact> value;
public:
    RectangleVisitor(Rectangle& shape);
    virtual ~RectangleVisitor();

    virtual void visit(Circle& shape);
    virtual void visit(Line& shape);
    virtual void visit(Rectangle& shape);

    std::unique_ptr<Contact> get();
};
}
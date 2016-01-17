#pragma once

namespace PongGame
{
class Circle;
class Line;
class Rectangle;

// Base visitor for shapes.
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor();

    virtual void visit(Circle& shape) = 0;
    virtual void visit(Line& shape) = 0;
    virtual void visit(Rectangle& shape) = 0;
};
}
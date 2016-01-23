#include "CollisionVisitor.h"

namespace PongGame
{
CollisionVisitor::CollisionVisitor(CollisionShape& s) : shape(s), value() {}

CollisionVisitor::~CollisionVisitor() {}

void CollisionVisitor::visit(Circle& circle)
{
    CircleVisitor visitor(circle);
    shape.accept(visitor);
    value = visitor.get();
}

void CollisionVisitor::visit(Line& line)
{
    LineVisitor visitor(line);
    shape.accept(visitor);
    value = visitor.get();
}

void CollisionVisitor::visit(Rectangle& rectangle)
{
    RectangleVisitor visitor(rectangle);
    shape.accept(visitor);
    value = visitor.get();
}

std::unique_ptr<Contact> CollisionVisitor::get()
{
    return std::move(value);
}
}
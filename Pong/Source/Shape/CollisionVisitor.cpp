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

void CollisionVisitor::visit(Line& shape)
{

}

void CollisionVisitor::visit(Rectangle& shape)
{

}
}
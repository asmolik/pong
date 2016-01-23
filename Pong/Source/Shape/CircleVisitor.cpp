#include "CircleVisitor.h"

namespace PongGame
{
CircleVisitor::CircleVisitor(Circle& s) : shape(s), value() {}

CircleVisitor::~CircleVisitor() {}

void CircleVisitor::visit(Circle& circle)
{
    
}

void CircleVisitor::visit(Line& line)
{
    value = Collision::intersect(this->shape, line);
}

void CircleVisitor::visit(Rectangle& rect)
{
    value = Collision::intersect(rect, this->shape);
}

std::unique_ptr<Contact> CircleVisitor::get()
{
    return std::move(value);
}
}
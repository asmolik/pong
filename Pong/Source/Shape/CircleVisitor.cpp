#include "CircleVisitor.h"

namespace PongGame
{
CircleVisitor::CircleVisitor(Circle& s) : shape(s), value() {}

CircleVisitor::~CircleVisitor() {}

void CircleVisitor::visit(Circle& circle)
{
    
}

void CircleVisitor::visit(Line& shape)
{
    Collision::intersect(this->shape, shape);
}

void CircleVisitor::visit(Rectangle& shape)
{
    Collision::intersect(shape, this->shape);
}
}
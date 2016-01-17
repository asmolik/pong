#include "Rectangle.h"

namespace PongGame
{
Rectangle::Rectangle(PositionComponent& p, float a, float b)
    : CollisionShape(p), a(a), b(b) {}

Rectangle::~Rectangle() {}

void Rectangle::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
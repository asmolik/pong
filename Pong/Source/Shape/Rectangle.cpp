#include "Rectangle.h"

namespace PongGame
{
Rectangle::Rectangle(GameObject& o, float a, float b, const Vec2& n)
    : CollisionShape(o), a(a), b(b), normal(n) {}

Rectangle::~Rectangle() {}

void Rectangle::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
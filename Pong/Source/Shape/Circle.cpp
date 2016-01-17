#include "Circle.h"

namespace PongGame
{
Circle::Circle(PositionComponent& p, float r) : CollisionShape(p), radius(r) {}

Circle::~Circle() {}

void Circle::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
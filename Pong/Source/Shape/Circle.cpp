#include "Circle.h"

namespace PongGame
{
Circle::Circle(GameObject& o, float r) : CollisionShape(o), radius(r) {}

Circle::~Circle() {}

void Circle::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
#include "Line.h"

namespace PongGame
{
Line::Line(GameObject& o, Vec2& n) : CollisionShape(o), normal(n) {}

Line::~Line() {}

void Line::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
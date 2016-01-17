#include "Line.h"

namespace PongGame
{
Line::Line(PositionComponent& p, Vec2 n) : CollisionShape(p), normal(n) {}

Line::~Line() {}

void Line::accept(ShapeVisitor& v)
{
    v.visit(*this);
}
}
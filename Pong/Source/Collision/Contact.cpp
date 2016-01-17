#include "RectangleCircle.h"

namespace PongGame
{
Contact::Contact(CollisionShape& shape1, CollisionShape& shape2, Vec2 normal,
    Vec2 point1, Vec2 point2, float impulse) 
    : shape1(shape1), shape2(shape2), normal(normal), point1(point1), 
    point2(point2), impulse(impulse) {}
}
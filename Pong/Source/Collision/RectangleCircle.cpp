#include "RectangleCircle.h"

namespace PongGame
{
namespace Collision
{
// Rectangle here is actually a line segment.
std::unique_ptr<Contact> intersect(Rectangle& r, Circle& c)
{
    // Velocity towards the line
    float d = Vec2::dot(c.position.velocity, r.normal);
    Vec2 velR = r.normal * d;
    // Dot product
    float dot = Vec2::dot(Vec2::normalize(velR), r.normal);

    // Circle moves parallel to the line
    if (dot < Constants::epsilon && dot > -Constants::epsilon)
    {
        return nullptr;
    }

    float distance = Vec2::dot(r.normal, r.position.position - c.position.position) / dot;
    float toi = distance / c.position.velocity.len();
    if (distance < -Constants::epsilon)
    {
        return nullptr;
    }
    // Does the circle hit the "rectangle". Calculate the collision point.
    // Account for rectangle's speed.
    Vec2 collisionPoint = c.position.position + c.position.velocity * toi;
    collisionPoint += -r.normal * c.radius;
    Vec2 rectPos = r.position.position + r.position.velocity * toi;
    if (collisionPoint.y < rectPos.y + r.b / 2 &&
        collisionPoint.y > rectPos.y - r.b / 2)
    {
        return std::make_unique<Contact>(r.object, c.object, r.normal, toi);
    }
    return nullptr;
}
}
}
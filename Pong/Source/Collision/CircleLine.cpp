#include "CircleLine.h"

namespace PongGame
{
namespace Collision
{
std::unique_ptr<Contact> intersect(Circle& c, Line& l)
{
    // Velocity towards the line
    float d = Vec2::dot(c.position.velocity, l.normal);
    Vec2 velR = l.normal * d;
    // Dot product
    float dot = Vec2::dot(Vec2::normalize(velR), l.normal);

    // Circle moves parallel to the line
    if (dot < Constants::epsilon && dot > -Constants::epsilon)
    {
        return nullptr;
    }
    
    float distance = Vec2::dot(l.normal, l.position.position - c.position.position) / dot;
    distance -= c.radius;
    float toi = distance / c.position.velocity.len();
    if (distance < -Constants::epsilon)
    {
        return nullptr;
    }

    return std::make_unique<Contact>(l.object, c.object, l.normal, toi);
}
}
}
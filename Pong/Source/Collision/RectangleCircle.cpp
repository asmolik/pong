#include "RectangleCircle.h"

namespace PongGame
{
namespace Collision
{
std::unique_ptr<Contact> intersect(Rectangle& r, Circle& c)
{
    /*float minDist = (fmaxf(r.a, r.b) / 2 + c.radius);
    minDist *= minDist;
    if ((r.position.position - c.position.position).len2() > minDist)
    {
        return nullptr;
    }*/

    if (fabsf(c.position.position.x - r.position.position.x) > c.radius + r.a / 2)
    {
        return nullptr;
    }
    Vec2 normal;

    return std::make_unique<Contact>(r, c, normal);
}
}
}
#include "CircleLine.h"

namespace PongGame
{
namespace Collision
{
std::unique_ptr<Contact> intersect(Circle& c, Line& l)
{
    /*float minDist = (fmaxf(r.a, r.b) / 2 + c.radius);
    minDist *= minDist;
    if ((r.position.position - c.position.position).len2() > minDist)
    {
        return nullptr;
    }*/

    if (fabsf(c.position.position.x - l.position.position.x) > c.radius)
    {
        return nullptr;
    }

    return std::make_unique<Contact>(l, c, l.normal, c.position.velocity.len());
}
}
}
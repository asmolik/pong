#pragma once

#include <memory>
#include "Physics/Vec2.h"

namespace PongGame
{
class CollisionShape;

class Contact
{
public:
    Contact(CollisionShape& shape1, CollisionShape& shape2, Vec2 normal, float impulse);

    CollisionShape& shape1;
    CollisionShape& shape2;

    // Points to shape2
    Vec2 normal;

    Vec2 point1;
    Vec2 point2;

    float impulse;
};
}
#pragma once

#include <functional>
#include "Collision/Contact.h"

namespace PongGame
{
// Methods describing object's behavior after registering events.
struct Behavior
{
    Behavior();
    virtual ~Behavior();

    // Function called after a collision was detected but before the collision
    // resolution. If it returns true the object will be affected by the
    // collision resolution.
    virtual bool collisionResponse(const Contact& contact);
    // Function called on both colliding objects after the collision was 
    // detected and resolved.
    virtual void onCollision(const Contact& contact);
};
}
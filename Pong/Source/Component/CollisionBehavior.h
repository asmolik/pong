#pragma once

#include "Component/Behavior.h"
#include "Object/GameObject.h"

namespace PongGame
{
// Class describing the behavior of a pong ball. It ignores the collision
// resolution with lines "left" and "right".
class CollisionBehavior : public Behavior
{
    GameObject& owner;
public:
    CollisionBehavior(GameObject& owner);

    virtual bool collisionResponse(const Contact& contact);

    virtual void onCollision(const Contact& contact);
};
}
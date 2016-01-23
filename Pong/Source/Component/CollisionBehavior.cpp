#include "CollisionBehavior.h"

namespace PongGame
{
CollisionBehavior::CollisionBehavior(GameObject& o) : owner(o) {}

bool CollisionBehavior::collisionResponse(const Contact& contact)
{
    if (contact.object1.name == "left" || contact.object1.name == "right")
    {
        return false;
    }
    return true;
}

void CollisionBehavior::onCollision(const Contact& contact)
{

}
}
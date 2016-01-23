#pragma once

#include <memory>
#include "Physics/Vec2.h"

namespace PongGame
{
class GameObject;

// Class representig a contact point in a collision between two objects.
class Contact
{
public:
    Contact(GameObject& object1, GameObject& object2, Vec2 normal, float timeOfImpact);

    GameObject& object1;
    GameObject& object2;

    // Points to object2
    Vec2 normal;

    Vec2 point1;
    Vec2 point2;

    float timeOfImpact;
};
}
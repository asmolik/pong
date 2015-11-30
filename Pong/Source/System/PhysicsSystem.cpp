#include "PhysicsSystem.h"

namespace PongGame
{
PhysicsSystem::PhysicsSystem() 
{
    objects.reserve(1024);
}

void PhysicsSystem::update()
{
    // find collisions

    // solve collisions

    // integrate velocities
    for (auto& obj : objects)
    {
        obj->position += obj->velocity * time;
    }

    // integrate forces
}

void PhysicsSystem::addObject(
    std::shared_ptr<PositionComponent> context)
{
    objects.push_back(context);
}

void PhysicsSystem::setTime(float time)
{
    this->time = time;
}
}
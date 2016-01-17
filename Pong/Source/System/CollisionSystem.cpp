#include "CollisionSystem.h"

namespace PongGame
{
CollisionSystem::CollisionSystem()
{
    objects.reserve(1024);
}

void CollisionSystem::update()
{
    // find collisions
    for (int i = 0; i < objects.size(); ++i)
    {
        for (int j = i + 1; j < objects.size(); ++j)
        {
            CollisionVisitor visitor(*objects[i]);
            objects[j]->accept(visitor);
            contacts.push_back(visitor.get());
        }
    }
    // solve collisions
    for (auto& c : contacts)
    {
        c->shape2.position.velocity = -c->shape2.position.velocity;
    }
}

void CollisionSystem::addObject(
    std::shared_ptr<CollisionShape> context)
{
    objects.push_back(context);
}

void CollisionSystem::setTime(float time)
{
    this->time = time;
}
}
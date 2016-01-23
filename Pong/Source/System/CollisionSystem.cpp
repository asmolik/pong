#include "CollisionSystem.h"

namespace PongGame
{
CollisionSystem::CollisionSystem()
{
    objects.reserve(1024);
}

void CollisionSystem::update()
{
    contacts.clear();

    // find collisions
    for (int i = 0; i < objects.size(); ++i)
    {
        for (int j = i + 1; j < objects.size(); ++j)
        {
            CollisionVisitor visitor(*objects[i]);
            objects[j]->accept(visitor);
            auto tmp = visitor.get();
            if (tmp != nullptr)
            {
                contacts.push_back(std::move(tmp));
            }
        }
    }
    // solve collisions
    for (auto& c : contacts)
    {
        if (c->timeOfImpact > time || c->timeOfImpact < 0)
        {
            continue;
        }
        // object2 is always the ball
        if (c->object2.behavior->collisionResponse(*c))
        {
            Vec2 impulse = calculateImpulse(*c);
            c->object2.position->apply(-impulse);
        }

        c->object1.behavior->onCollision(*c);
        c->object2.behavior->onCollision(*c);
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

Vec2 CollisionSystem::calculateImpulse(const Contact& c)
{
    Vec2 relVel = c.object2.position->velocity - c.object1.position->velocity;
    float dot = Vec2::dot(relVel, c.normal) * 2;
    return c.normal * dot;
}
}
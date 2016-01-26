#pragma once

#include <memory>
#include <tuple>
#include <vector>
#include "Component/PositionComponent.h"
#include "Shape/CollisionShape.h"
#include "Shape/CollisionVisitor.h"

namespace PongGame
{
//
// Detects collisions, solves them and notifies objects about them.
//
class CollisionSystem
{
    std::vector<std::shared_ptr<CollisionShape>> objects;
    std::vector<std::unique_ptr<Contact>> contacts;
    float time;
public:
    CollisionSystem();

    void update();
    void addObject(std::shared_ptr<CollisionShape> object);
    void setTime(float time);

private:
    Vec2 calculateImpulse(const Contact& c);
};
}
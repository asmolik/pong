#pragma once

#include <memory>
#include "GameObject.h"
#include "Shape/Rectangle.h"

namespace PongGame
{
class Paddle : public GameObject
{
public:
    Paddle(float length, Vec2& normal);
    virtual ~Paddle();
    std::shared_ptr<CollisionShape> shape;
};
}
#pragma once

#include <memory>
#include "GameObject.h"
#include "Shape/Circle.h"

namespace PongGame
{
class Ball : public GameObject
{
public:
    Ball();
    virtual ~Ball();
    std::shared_ptr<CollisionShape> shape;
};
}
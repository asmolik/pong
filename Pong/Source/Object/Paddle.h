#pragma once

#include <memory>
#include "GameObject.h"

namespace PongGame
{
class Paddle : public GameObject
{
public:
    Paddle();
    virtual ~Paddle();
};
}
#pragma once

#include <memory>
#include "GameObject.h"

namespace PongGame
{
class Ball : public GameObject
{
public:
    Ball();
    virtual ~Ball();
};
}
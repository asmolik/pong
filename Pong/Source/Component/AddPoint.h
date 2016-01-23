#pragma once

#include "Component/Behavior.h"
#include "Object/GameObject.h"
#include "Game/GameInfo.h"

namespace PongGame
{
// Class describing the behavior of the vertical lines of the pong field.
// Changes the score based on the name of the line in onCollision method.
class AddPoint : public Behavior
{
    GameInfo& info;
public:
    AddPoint(GameInfo& info);

    virtual bool collisionResponse(const Contact& contact);

    virtual void onCollision(const Contact& contact);
};
}
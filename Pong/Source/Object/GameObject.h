#pragma once

#include <memory>
#include "Component/PositionComponent.h"

namespace PongGame
{
class GameObject
{
    
public:
    GameObject();
    GameObject(std::shared_ptr<PositionComponent>& position);
    virtual ~GameObject();
    std::shared_ptr<PositionComponent> position;
};
}
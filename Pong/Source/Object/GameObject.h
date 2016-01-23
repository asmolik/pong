#pragma once

#include <string>
#include <memory>
#include "Component/PositionComponent.h"
#include "Component/Behavior.h"

namespace PongGame
{
class GameObject
{
    typedef std::shared_ptr<PositionComponent> PositionComponentP;
public:
    std::string name;
    std::shared_ptr<PositionComponent> position;
    std::unique_ptr<Behavior> behavior;

    GameObject();
    explicit GameObject(const std::string& name);
    explicit GameObject(const PositionComponentP& position);
    GameObject(const std::string& name, const PositionComponentP& position);
    virtual ~GameObject();
};
}
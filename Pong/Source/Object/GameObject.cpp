#include "GameObject.h"

namespace PongGame
{
GameObject::GameObject() 
    : position(std::make_shared<PositionComponent>()) {}

GameObject::GameObject(const PositionComponent& position)
    : position(std::make_shared<PositionComponent>(position)) {}

GameObject::~GameObject() {}
}
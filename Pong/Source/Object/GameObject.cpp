#include "GameObject.h"

namespace PongGame
{
GameObject::GameObject() 
    : position(std::make_shared<PositionComponent>()) {}

GameObject::GameObject(std::shared_ptr<PositionComponent>& position)
    : position(position) {}

GameObject::~GameObject() {}
}
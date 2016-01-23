#include "GameObject.h"

namespace PongGame
{
GameObject::GameObject()
    : GameObject("", std::make_shared<PositionComponent>()) {}

GameObject::GameObject(const std::string& n)
    : GameObject(n, std::make_shared<PositionComponent>()) {}

GameObject::GameObject(const PositionComponentP& position)
    : GameObject("", position) {}

GameObject::GameObject(const std::string& n, const PositionComponentP& position)
    : name(n), position(position), behavior(std::make_unique<Behavior>()) {}

GameObject::~GameObject() {}
}
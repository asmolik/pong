#include "Behavior.h"

namespace PongGame
{
Behavior::Behavior() {}

Behavior::~Behavior() {}

bool Behavior::collisionResponse(const Contact& contact) { return true; }

void Behavior::onCollision(const Contact& contact) {}
}
#include "CollisionShape.h"

namespace PongGame
{
CollisionShape::CollisionShape(GameObject& o) : object(o), position(*o.position) {}
CollisionShape::~CollisionShape() {}
}
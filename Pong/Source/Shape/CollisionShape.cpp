#include "CollisionShape.h"

namespace PongGame
{
CollisionShape::CollisionShape(PositionComponent& p) : position(p) {}
CollisionShape::~CollisionShape() {}
}
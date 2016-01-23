#include "Ball.h"

namespace PongGame
{
Ball::Ball(float radius) : shape(std::make_shared<Circle>(*this, radius)) {}

Ball::~Ball() {}
}
#include "Ball.h"

namespace PongGame
{
Ball::Ball() : shape(std::make_shared<Circle>(this->position)) {}

Ball::~Ball() {}
}
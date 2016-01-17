#include "Paddle.h"

namespace PongGame
{
Paddle::Paddle() : shape(std::make_shared<Rectangle>(this->position)) {}

Paddle::~Paddle() {}
}
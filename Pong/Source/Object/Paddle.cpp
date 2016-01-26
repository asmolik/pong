#include "Paddle.h"

namespace PongGame
{
Paddle::Paddle(float length, const Vec2& n) 
    : shape(std::make_shared<Rectangle>(*this, 2.0f, length, n)) {}

Paddle::~Paddle() {}
}
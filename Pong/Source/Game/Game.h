#pragma once

#include <vector>
#include <memory>
#include "Input/InputContext.h"
#include "Input/InputCommandFactory.h"
#include "System/InputSystem.h"
#include "System/PhysicsSystem.h"
#include "Object/Ball.h"
#include "Object/Paddle.h"

namespace PongGame
{
///
/// A pong game.
///
class Game
{
    std::unique_ptr<InputSystem> input;
    std::unique_ptr<PhysicsSystem> physics;

    Ball ball;
    Paddle paddle1;
    Paddle paddle2;

public:
    Game();
    Game(const Game&);

    void tick(float time);
    float get();
};
}
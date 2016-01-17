#pragma once

#include <vector>
#include <memory>
#include "Input/InputContext.h"
#include "Input/InputCommandFactory.h"
#include "System/InputSystem.h"
#include "System/PhysicsSystem.h"
#include "System/CollisionSystem.h"
#include "Object/Ball.h"
#include "Object/Paddle.h"
#include "Shape/Line.h"

namespace PongGame
{
///
/// A pong game.
///
class Game
{
    std::unique_ptr<InputSystem> input;
    std::unique_ptr<PhysicsSystem> physics;
    std::unique_ptr<CollisionSystem> collision;

    Ball ball;
    Paddle paddle1;
    Paddle paddle2;

    int p1score;
    int p2score;

    int max;

public:
    Game();
    Game(const Game&);

    void tick(float time);
    float get();
};
}
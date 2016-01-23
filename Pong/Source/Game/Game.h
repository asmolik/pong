#pragma once

#include <vector>
#include <memory>
#include "GameInfo.h"
#include "Input/InputContext.h"
#include "Input/InputRange.h"
#include "Input/RangeCommand.h"
#include "System/InputSystem.h"
#include "System/PhysicsSystem.h"
#include "System/CollisionSystem.h"
#include "Object/Ball.h"
#include "Object/Paddle.h"
#include "Shape/Line.h"
#include "Component/CollisionBehavior.h"
#include "Component/AddPoint.h"

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

    std::vector<InputRange> ranges;

    Ball ball;
    Paddle paddle1;
    Paddle paddle2;
    GameObject lineLeft;
    std::shared_ptr<Line> left;
    GameObject lineRight;
    std::shared_ptr<Line> right;
    GameObject lineTop;
    std::shared_ptr<Line> top;
    GameObject lineBottom;
    std::shared_ptr<Line> bottom;

    GameInfo info;

public:
    Game();
    Game(const GameInfo&);
    Game(const Game&);

    void setWidth(float width);
    void setHeight(float height);
    void setBallVelocity(float x, float y);
    void setBallPosition(float x, float y);

    void registerInput(InputRange& input);

    void tick(float time);
    GameInfo get();

private:
    void setupInput();
    //makes sure paddles and ball stay on the field
    void checkConstraints();
};
}
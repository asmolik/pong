#include "Game.h"

namespace PongGame
{
Game::Game() : Game(GameInfo()) {}

Game::Game(const GameInfo& info)
    : paddle1(info.paddle1Length, Vec2(1.0f, 0.0)), paddle2(info.paddle2Length, Vec2(-1.0f, 0.0)),
    ball(info.ballSize), info(info), lineLeft(GameObject("left")), lineRight(GameObject("right")),
    left(std::make_shared<Line>(lineLeft, Vec2(1.0f, 0.0f))),
    right(std::make_shared<Line>(lineRight, Vec2(-1.0f, 0.0f))),
    top(std::make_shared<Line>(lineTop, Vec2(0.0f, -1.0f))),
    bottom(std::make_shared<Line>(lineBottom, Vec2(0.0f, 1.0f)))
{
    setupInput();

    ball.name = "ball";
    paddle1.name = "paddle1";
    paddle2.name = "paddle2";
    lineLeft.name = "left";
    lineRight.name = "right";
    lineTop.name = "lineTop";
    lineBottom.name = "lineBottom";

    ball.position->position.x = info.fieldWidth / 2;
    ball.position->position.y = info.fieldHeight / 2;
    ball.behavior = std::make_unique<CollisionBehavior>(ball);

    paddle1.position->position.x = 50.0f;
    paddle2.position->position.x = info.fieldWidth - 50.0f;
    paddle1.position->position.y = info.fieldHeight / 2;
    paddle2.position->position.y = info.fieldHeight / 2;

    lineLeft.behavior = std::make_unique<AddPoint>(this->info);
    lineRight.behavior = std::make_unique<AddPoint>(this->info);
    lineTop.behavior = std::make_unique<Behavior>();
    lineBottom.behavior = std::make_unique<Behavior>();

    physics = std::make_unique<PhysicsSystem>();
    physics->addObject(ball.position);
    physics->addObject(paddle1.position);
    physics->addObject(paddle2.position);

    collision = std::make_unique<CollisionSystem>();
    collision->addObject(ball.shape);
    collision->addObject(paddle1.shape);
    collision->addObject(paddle2.shape);
    lineRight.position->position.x = 160.0f;
    collision->addObject(left);
    collision->addObject(right);
    collision->addObject(top);
    collision->addObject(bottom);

    ball.position->velocity = Vec2(2.0f, 0.0f);
}

Game::Game(const Game&) : paddle1(10.0f, Vec2(1.0f, 0.0)), paddle2(10.0f, Vec2(-1.0f, 0.0)), ball(5.0f)
{

}

void Game::setWidth(float width)
{
    info.fieldWidth = width;
    right->position.position.x = width;
    paddle2.position->position.x = width - 50.0f;
}

void Game::setHeight(float height)
{
    info.fieldHeight = height;
    top->position.position.y = height;
}

void Game::setBallVelocity(float x, float y)
{
    ball.position->velocity.x = x;
    ball.position->velocity.y = y;
}

void Game::setBallPosition(float x, float y)
{
    ball.position->position.x = x;
    ball.position->position.y = y;
}

void Game::registerInput(InputRange& input)
{
    ranges.push_back(input);
}

void Game::tick(float time)
{
    // input
    input->setInput(ranges);
    input->update();
    ranges.clear();
    // collision
    collision->setTime(time);
    collision->update();
    // physics
    physics->setTime(time);
    physics->update();

    // clear velocity of paddles
    paddle1.position->velocity = Vec2();
    paddle2.position->velocity = Vec2();
    
    checkConstraints();

    info.ballPos = ball.position->position;
    info.p1Pos = paddle1.position->position;
    info.p2Pos = paddle2.position->position;
}

GameInfo Game::get()
{
    return info;
}

void Game::setupInput()
{
    input = std::make_unique<InputSystem>();
    auto context = std::make_unique<InputContext>();

    auto p1 = std::make_unique<RangeCommand>(*paddle1.position);
    auto p2 = std::make_unique<RangeCommand>(*paddle2.position);

    context->addMapping(InputRange(1), std::move(p1));
    context->addMapping(InputRange(2), std::move(p2));
    input->addContext(std::move(context));
}

void Game::checkConstraints()
{
    if (paddle1.position->position.y > info.fieldHeight)
    {
        paddle1.position->position.y = info.fieldHeight;
    }
    if (paddle1.position->position.y < 0)
    {
        paddle1.position->position.y = 0;
    }
    if (paddle2.position->position.y > info.fieldHeight)
    {
        paddle2.position->position.y = info.fieldHeight;
    }
    if (paddle2.position->position.y < 0)
    {
        paddle2.position->position.y = 0;
    }
}
}
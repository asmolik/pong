#include "Object/Ball.h"
#include "Object/Paddle.h"
#include "Shape/Line.h"
#include "System/CollisionSystem.h"
#include "System/PhysicsSystem.h"
#include "Component/CollisionBehavior.h"
#include "Component/AddPoint.h"
#include "../Pong.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace PongGame;

// file for debugging in visual studio
int main()
{
    InputSystem input;
    auto context = std::make_unique<InputContext>();
    Paddle paddle1(10.0f, Vec2(1.0f, 0.0f));
    auto p1 = std::make_unique<RangeCommand>(*paddle1.position);
    auto p2 = std::make_unique<RangeCommand>(*paddle1.position);
    context->addMapping(InputRange(1), std::move(p1));
    input.addContext(std::move(context));
    std::vector<InputRange> ranges;
    std::vector<Input> inputs;
    InputRange r(1);
    Input inn(2);
    inputs.push_back(inn);
    r.set(1.0f);
    ranges.push_back(r);

    Pong pong;
    pong.setBallVelocity(300.0f, 0.0f);
    pong.setWidth(900.0f);
    pong.setHeight(300.0f);
    while (true)
    {
        pong.run(0.02f);
        std::cout << pong.get().ballPos.x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }


    CollisionSystem collision;
    PhysicsSystem physics;
    collision.setTime(1 / 30.0f);
    physics.setTime(1 / 30.0f);

    Ball ball(5.0f);
    ball.position->velocity = Vec2(40.0f, 20.0f);
    ball.position->position.x = 154.0f;
    ball.behavior = std::make_unique<CollisionBehavior>(ball);

    Paddle paddle(10.0f, Vec2(1.0f, 0.0f));
    paddle.position->position.x = 40.0f;
    paddle.position->position.y = 40.0f;

    GameObject lineLeft("left");
    GameObject lineRight("right");
    lineRight.position->position.x = 160.0f;
    GameObject lineTop;
    lineTop.position->position.y = 90.0f;
    GameObject lineBottom;

    GameInfo info;
    lineLeft.behavior = std::make_unique<AddPoint>(info);
    lineRight.behavior = std::make_unique<AddPoint>(info);
    lineTop.behavior = std::make_unique<Behavior>();
    lineBottom.behavior = std::make_unique<Behavior>();

    //collision.addObject(paddle.shape);
    collision.addObject(ball.shape);
    collision.addObject(std::make_shared<Line>(lineRight, Vec2(-1.0f, 0.0f)));
    collision.addObject(std::make_shared<Line>(lineLeft, Vec2(1.0f, 0.0f)));
    collision.addObject(std::make_shared<Line>(lineTop, Vec2(0.0f, -1.0f)));
    collision.addObject(std::make_shared<Line>(lineBottom, Vec2(0.0f, 1.0f)));

    physics.addObject(ball.position);

    while (true)
    {
        collision.update();
        physics.update();
        std::cout << ball.position->velocity.x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
}
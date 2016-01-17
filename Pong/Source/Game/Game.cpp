#include "Game.h"

namespace PongGame
{
Game::Game()
{
    input = std::make_unique<InputSystem>();
    auto context = std::make_unique<InputContext>(
        std::make_unique<InputCommandFactory>());
    //context->addMapping();
    input->addContext(std::move(context));

    ball.position->position.x = 80.0f;
    physics = std::make_unique<PhysicsSystem>();
    physics->addObject(ball.position);
    physics->addObject(paddle1.position);
    physics->addObject(paddle2.position);

    collision = std::make_unique<CollisionSystem>();
    collision->addObject(ball.shape);
    /*collision->addObject(paddle1.shape);
    collision->addObject(paddle2.shape);*/
    collision->addObject(std::make_shared<Line>(PositionComponent(Vec2(0.0f)), Vec2(1.0f, 0.0f)));
    collision->addObject(std::make_shared<Line>(PositionComponent(Vec2(160.0f)), Vec2(-1.0f, 0.0f)));

    ball.position->velocity = Vec2(2.0f, 0.0f);
}

Game::Game(const Game&)
{

}

void Game::tick(float time)
{
    // input
    input->update();
    // collision
    collision->update();
    // physics
    physics->setTime(time);
    physics->update();
}

float Game::get()
{
    return ball.position->position.x;
}
}
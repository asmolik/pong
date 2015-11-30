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

    physics = std::make_unique<PhysicsSystem>();
    physics->addObject(ball.position);
    physics->addObject(paddle1.position);
    physics->addObject(paddle2.position);

    ball.position->velocity = Vec2(1.0f, 0.0f);
}

Game::Game(const Game&)
{

}

void Game::tick(float time)
{
    // input
    input->update();
    // physics
    physics->setTime(time);
    physics->update();
}

float Game::get()
{
    return ball.position->position.x;
}
}
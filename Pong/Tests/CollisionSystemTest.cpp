#include "Object/Ball.h"
#include "Object/GameObject.h"
#include "Shape/Line.h"
#include "System/CollisionSystem.h"
#include "Component/CollisionBehavior.h"

#define BOOST_TEST_MODULE Collision Test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(collision_system_test)
{
    PongGame::CollisionSystem collision;

    PongGame::Ball ball(5.0f);
    ball.position->velocity = PongGame::Vec2(40.0f, 0.0f);
    ball.position->position.x = 154.0f;
    ball.behavior = std::make_unique<PongGame::CollisionBehavior>(ball);
    PongGame::GameObject lineRight;
    lineRight.position->position.x = 160.0f;

    collision.addObject(ball.shape);
    collision.addObject(std::make_shared<PongGame::Line>(lineRight, PongGame::Vec2(-1.0f, 0.0f)));
    
    BOOST_CHECK(ball.position->velocity.x > 0);
    collision.update();
    BOOST_CHECK(ball.position->velocity.x < 0);
}
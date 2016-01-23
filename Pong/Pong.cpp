#include "Pong.h"

Pong::Pong() {}

void Pong::setWidth(float width)
{
    pong.setWidth(width);
}

void Pong::setHeight(float height)
{
    pong.setHeight(height);
}

void Pong::setBallVelocity(float x, float y)
{
    pong.setBallVelocity(x, y);
}

void Pong::setBallPosition(float x, float y)
{
    pong.setBallPosition(x, y);
}

void Pong::run(float time)
{
    pong.tick(time);
}

PongGame::GameInfo Pong::get()
{
    return pong.get();
}

void Pong::p1input(float r) {
    PongGame::InputRange in(1);
    in.set(r);
    pong.registerInput(in);
}

void Pong::p2input(float r) {
    PongGame::InputRange in(2);
    in.set(r);
    pong.registerInput(in);
}

int Pong::p1score() {
    return pong.get().player1Score;
}

int Pong::p2score() {
    return pong.get().player2Score;
}
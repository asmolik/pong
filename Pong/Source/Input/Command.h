#pragma once

namespace PongGame
{
//
// A game command.
//
class Command
{
public:
    virtual ~Command();
    virtual void execute() = 0;
};
}
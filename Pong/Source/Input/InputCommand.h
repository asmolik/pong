#pragma once

#include <memory>

namespace PongGame
{
class CommandVisitor;

///
/// A game command.
///
class InputCommand : public std::enable_shared_from_this<InputCommand>
{
public:
    virtual ~InputCommand();
    virtual void execute() = 0;
    virtual void accept(CommandVisitor& v) = 0;
};
}
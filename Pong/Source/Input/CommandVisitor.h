#pragma once
#include <memory>
#include "RawInput.h"
#include "RawInputVisitor.h"
#include "InputCommand.h"

namespace PongGame
{
class CommandVisitor
{
public:
    virtual ~CommandVisitor();
    virtual void visit(InputCommand& input) = 0;
};
}
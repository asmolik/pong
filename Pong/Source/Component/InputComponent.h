#pragma once

#include <map>
#include "Input/Command.h"

namespace PongGame
{
struct InputComponent
{
public:
    InputComponent();
    virtual ~InputComponent();

    virtual void accept(Command& command);
};
}
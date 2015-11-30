#pragma once

namespace PongGame
{
class RawInput;

class RawInputVisitor
{
public:
    virtual ~RawInputVisitor();
    virtual void visit(RawInput& input) = 0;
};
}
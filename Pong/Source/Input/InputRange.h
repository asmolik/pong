#pragma once

#include "Input.h"

namespace PongGame
{
// Range is an input with a value from -1.0 to 1.0.
class InputRange : public Input
{
protected:
    float range;
public:
    InputRange(int id);
    virtual ~InputRange();

    void set(float value);
    float get() const;

    bool operator==(const InputRange& other) const;
    bool operator!=(const InputRange& other) const;
    bool operator< (const InputRange& other) const;
};
}
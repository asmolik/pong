#pragma once


namespace PongGame
{
// An input action (for example a key press).
class Input
{
protected:
    int id;
public:
    explicit Input(int id);
    virtual ~Input();

    bool operator==(const Input& other) const;
    bool operator!=(const Input& other) const;
    bool operator< (const Input& other) const;
};
}
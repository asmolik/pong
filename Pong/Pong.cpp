#include "Pong.h"

Pong::Pong(int x) {
    this->x = x;
}

int Pong::get() {
    return pong.get();
}

void Pong::run() {
    pong.tick(1.0f);
    ++x;
}
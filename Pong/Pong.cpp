#include "Pong.h"

Pong::Pong(int x) {
	this->x = x;
}

int Pong::get() {
	return x;
}

void Pong::run() {
	++x;
}
#pragma once
#include <raylib.h>
#include "Character.hpp"

class Dog : public Character {
public:
	Dog(const char* folder, Vector2 position, int speed)
		:Character(folder, position, speed) {
	}
	void Update(Vector2 catpos);
private:
};
#pragma once
#include <raylib.h>
#include "Character.hpp"

class Cat : public Character {
public:
	Cat(const char* folder, Vector2 position, int speed)
		:Character(folder, position, speed)	{
	}
	void Update();
private:
};
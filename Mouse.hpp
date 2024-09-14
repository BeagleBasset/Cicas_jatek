#pragma once
#include <raylib.h>
#include "Character.hpp"

class Mouse : public Character {
public:
	Mouse(const char* folder, Vector2 position, int speed)
		:Character(folder, position, speed) {
	}
	void Update(Vector2 dogpos);
private:
};
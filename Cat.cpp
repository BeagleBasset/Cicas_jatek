#include "Cat.hpp"




void Cat::Update()
{
	if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
		Position.x += Speed;
		MoveDirection = 1;
		Mirror = 1;
	}
	if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
		Position.x -= Speed;
		MoveDirection = 2;
		Mirror = -1;
	}
	if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) Position.y -= Speed;
	if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) Position.y += Speed;
	if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
		Position.x += (Speed / 1.41);
		Position.y -= (Speed / 1.41);
	}
	if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
		Position.x -= (Speed / 1.41);
		Position.y -= (Speed / 1.41);
	}
	if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
		Position.x += (Speed / 1.41);
		Position.y += (Speed / 1.41);
	}
	if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
		Position.x -= (Speed / 1.41);
		Position.y += (Speed / 1.41);
	}
	BorderCheck();
	
}


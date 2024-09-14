#include "Mouse.hpp"



void Mouse::Update(Vector2 dogpos)
{


	if (Position.x - dogpos.x > GetRandomValue(50, 200))
		Position.x -= Speed;
	if (Position.x - dogpos.x < GetRandomValue(-200, 0))
		Position.x += Speed;
	if (Position.y - dogpos.y > GetRandomValue(50, 200))
		Position.y -= Speed;
	if (Position.y - dogpos.y < GetRandomValue(-200, 0))
		Position.y += Speed;


	BorderCheck();
}



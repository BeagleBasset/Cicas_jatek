#include "Dog.hpp"

void Dog::Update(Vector2 catpos)
{
	if(Position.x - catpos.x > 0 && Position.y == catpos.y)
		Position.x -= Speed;
	if (Position.x - catpos.x < 0 && Position.y == catpos.y)
		Position.x += Speed;
	if (Position.y - catpos.y > 0 && Position.x == catpos.x)
		Position.y -= Speed;
	if (Position.y - catpos.y < 0 && Position.x == catpos.x)
		Position.y += Speed;
	if (Position.x - catpos.x > 0 && Position.y != catpos.y)
		Position.x -= (Speed / 1.41);
	if (Position.x - catpos.x < 0 && Position.y != catpos.y)
		Position.x += (Speed / 1.41);
	if (Position.y - catpos.y > 0 && Position.x != catpos.x)
		Position.y -= (Speed / 1.41);
	if (Position.y - catpos.y < 0 && Position.x != catpos.x)
		Position.y += (Speed / 1.41);
	BorderCheck();

}

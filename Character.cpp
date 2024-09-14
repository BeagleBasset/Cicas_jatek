#include "Character.hpp"



Character::Character(const char* folder, Vector2 position, int speed)
{
	Image = LoadTexture(folder);
	Image2 = { 0 }; 
	FrameWidth = 0;
	MaxFrames = 0;
	Position.x = position.x;
	Position.y = position.y;
	Speed = speed;

}

Character::~Character()
{
	UnloadTexture(Image);
}

void Character::Draw()
{
	switch (MoveDirection) {
	case 0:
		DrawTextureV(Image, Position, WHITE);
		break;
	case 1:
		DrawMotion(Image2, Mirror);
		MoveDirection = 0;
		break;
	case 2:
		DrawMotion(Image2, Mirror);
		MoveDirection = 0;
		break;
	}
	

}

Vector2 Character::GetPos()
{
	return Position;
}

Rectangle Character::GetRect()
{
	return Rectangle{ Position.x, Position.y, float(Image.width), float(Image.height) };
}

void Character::LoadImage(const char* folder2)
{
	Image2 = LoadTexture(folder2);
	FrameWidth = Image2.width / 2;
	MaxFrames = (Image2.width / FrameWidth);
}

void Character::BorderCheck()
{
	if (Position.x < 0)
		Position.x = GetScreenWidth() - Image.width;
	if (Position.x + Image.width > GetScreenWidth())
		Position.x = 0;
	if (Position.y < OffsetValue)
		Position.y = GetScreenHeight() - Image.height;
	if (Position.y + Image.height > GetScreenHeight())
		Position.y = OffsetValue;

}

void Character::DrawMotion(Texture2D image, int mirror)
{
	Timer += GetFrameTime();
	if (Timer >= Duration) {
		Timer = 0.0f;
		Frame += 1;
	}
	Frame = Frame % MaxFrames;
	DrawTextureRec(
		image,
		Rectangle{
			((float)FrameWidth * Frame),
			0,
			(float)mirror*(float)FrameWidth,
			(float)image.height },
		Position,
		WHITE);
}

void Character::GetRandomPosition(Vector2 firstpos, Vector2 secondpos)
{
	int newpositionx = GetRandomValue(10, GetScreenWidth() - Image.height);
	int newpositiony = GetRandomValue(OffsetValue + 10, GetScreenWidth() - Image.width);
	if (newpositionx != firstpos.x && newpositiony != firstpos.y && newpositionx != secondpos.x && newpositiony != secondpos.y) {
		Position.x = newpositionx;
		Position.y = newpositiony;
	}
}


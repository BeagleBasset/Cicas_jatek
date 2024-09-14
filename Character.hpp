#pragma once
#include <raylib.h>

class Character {
public:
	Character(const char* folder, Vector2 position, int speed);
	virtual ~Character();
	void Draw();
	Vector2 GetPos();
	Rectangle GetRect();
	void LoadImage(const char* folder2);
	void BorderCheck();
	void DrawMotion(Texture2D image, int mirror);
	const int OffsetValue{ 50 };
	void GetRandomPosition(Vector2 firstpos, Vector2 secondpos);
protected:
	Texture2D Image;
	Texture2D Image2;
	Vector2 Position;
	int Mirror = 1;
	int FrameWidth;
	int MaxFrames;
	int Speed{};
	int Frame{ 0 };
	int FramesCounter{ 0 };
	int FramesSpeed{ 8 };
	float Timer{ 0.0f };
	float Duration{ 0.07f };
	int MoveDirection{ 0 };

};
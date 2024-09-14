#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include "Character.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Mouse.hpp"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void CollisionCheck();
	void GameOver();
	bool ElapsedTimeCheck(bool result, float interval);
	void CheckForHighScore();
	void SaveHighScoreToFile(int highscore);
	int  LoadHighScoreFromFile();
	void StartScreen();
	//Variables
	int Score{ 0 };
	int HighScore{ 0 };
	bool Run = true;
	bool Start = true;
	
	
private:
	//Variables
	float ElapsedTime = 0.0f;
	float BlinkInterval = 1.0f; // Blink for GameOver
	bool IsShowText = true; // Blink for GameOver
	bool IsHighScore = false;
	//Start Cat
	Vector2 CatPos;
	int CatSpeed = 6;
	Vector2 CatStartPos = { 100, 100 };
	const char CatFile[24] = "Graphic/cat1-export.png";
	//end Cat
	//start Dog
	Vector2 DogPos;
	int DogSpeed = 3;
	Vector2 DogStartPos = { 500, 500 };
	const char DogFile[17] = "Graphic/dog1.png";
	//end Dog
	//start Mouse
	Vector2 MousePos;
	int MouseSpeed = 6;
	Vector2 MouseStartPos = { 400, 50 };
	const char MouseFile[19] = "Graphic/mouse1.png";
	//end Mouse
	//Init
	Cat cat;
	Dog dog;
	Mouse mouse;
	
	
};
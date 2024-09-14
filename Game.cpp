#include "Game.hpp"

Game::Game()
	: cat(CatFile, CatStartPos, CatSpeed),
	  dog(DogFile, DogStartPos, DogSpeed),
	  mouse(MouseFile, MouseStartPos, MouseSpeed)
{
	cat.LoadImage("Graphic/cat2.png");
	
}

Game::~Game()
{

}

void Game::Draw()
{
	cat.Draw();
	dog.Draw();
	mouse.Draw();
}

void Game::Update()
{
	cat.Update();
	CatPos = cat.GetPos();
	dog.Update(CatPos);
	DogPos = dog.GetPos();
	mouse.Update(DogPos);
	MousePos = mouse.GetPos();

}

void Game::CollisionCheck()
{
	Rectangle catrectangle = cat.GetRect();
	Rectangle dogrectangle = dog.GetRect();
	Rectangle mouserectangle = mouse.GetRect();
	//Cat and dog collision check
	if (CheckCollisionRecs(catrectangle, dogrectangle)) {
		Run = false;
		std::cout << "Gameover" << std::endl;
	}
	//Cat and mouse collision check
	if (CheckCollisionRecs(catrectangle, mouserectangle)) {
		Score++;
		mouse.GetRandomPosition(DogPos, CatPos);
		std::cout << "Score:" << Score << std::endl;
	}
		

}



void Game::GameOver()
{
	CheckForHighScore(); //Save the highscore to highscore.txt
	if (IsHighScore) {
		DrawText(TextFormat("GAMEOVER!"), 275, 150, 40, WHITE);
		DrawText(TextFormat("NEW EPIC HIGHSCORE: %d", Score), 150, 200, 40, WHITE);
		DrawText(TextFormat("CONGRATULATIONS!"), 200, 250, 40, RED);
	}
	else {
		DrawText(TextFormat("GAMEOVER!"), 275, 150, 40, WHITE);
		DrawText(TextFormat("YOUR SCORE: %d", Score), 237, 200, 40, WHITE);
	}

	IsShowText = ElapsedTimeCheck(IsShowText, BlinkInterval);
	if(IsShowText)
		DrawText(TextFormat("PRESS SPACE TO PLAY AGAIN!"), 80, 500, 40, WHITE);
	if (IsKeyPressed(KEY_SPACE)) {
		Score = 0;
		IsHighScore = false;
		//New positions of characters
		cat.GetRandomPosition(DogPos, MousePos);
		dog.GetRandomPosition(CatPos, MousePos);
		mouse.GetRandomPosition(CatPos, DogPos);
		Run = true;
	}

}

bool Game::ElapsedTimeCheck(bool result, float interval)
{
	ElapsedTime += GetFrameTime(); 
	if (ElapsedTime >= interval) {
		ElapsedTime = 0.0f; 
		return !result; 
	}
	return result; 
}

void Game::CheckForHighScore()
{
	if (Score > HighScore) {
		HighScore = Score;
		IsHighScore = true;
		SaveHighScoreToFile(HighScore);
	}
}

void Game::SaveHighScoreToFile(int highscore)
{
	std::ofstream highscoreFile("highscore.txt");
	if (highscoreFile.is_open()) {
		highscoreFile << highscore;
		highscoreFile.close();
	}
	else {
		std::cerr << "Failed to save highscore to file" << std::endl;
	}
}

int Game::LoadHighScoreFromFile()
{
	int loadedHighscore = 0;
	std::ifstream highscoreFile("highscore.txt");
	if (highscoreFile.is_open()) {
		highscoreFile >> loadedHighscore;
		highscoreFile.close();
	}
	else {
		std::cerr << "Failed to load highscore from file." << std::endl;
	}
	return loadedHighscore;
}

void Game::StartScreen()
{
	DrawText(TextFormat("CATGAME"), 200, 150, 80, WHITE);
	DrawText(TextFormat("USE THE ARROWKEYS TO CATCH THE MOUSE"), 100, 300, 25, WHITE);
	DrawText(TextFormat("WITH THE CAT!"), 300, 350, 25, WHITE);
	IsShowText = ElapsedTimeCheck(IsShowText, BlinkInterval);
	if (IsShowText)
		DrawText(TextFormat("PRESS SPACE TO PLAY AGAIN!"), 80, 500, 40, WHITE);
	if (IsKeyPressed(KEY_SPACE))
		Start = false;
}

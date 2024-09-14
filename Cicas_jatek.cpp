#include <raylib.h>
#include "Game.hpp"

const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 600;



int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };



    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Cica");
    SetTargetFPS(60);


    Game game;

    game.HighScore = game.LoadHighScoreFromFile();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        DrawLine(0, 49, GetScreenWidth(), 49, WHITE);
        DrawText(TextFormat("SCORE: %d", game.Score), 5, 5, 40, WHITE);
        DrawText(TextFormat("HIGHSCORE: %d", game.HighScore), 420, 5, 40, WHITE);
        ClearBackground(Dark_Green);
        //ingame state
        if (game.Start) {
            game.StartScreen();
        }
        else {
            if (game.Run) {
                game.Update();
                game.Draw();
                game.CollisionCheck();
            }
            else
                game.GameOver(); //gameover state
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

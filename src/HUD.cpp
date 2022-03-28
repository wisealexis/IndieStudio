/*
** EPITECH PROJECT, 2021
** indie
** File description:
** HUD
*/

#include "HUD.hpp"

Hud::Hud()
{
}

Hud::~Hud()
{
}

void Hud::drawHelp()
{
    DrawRectangle(170, 10, 450, 100, BEIGE);
    DrawRectangleLines(170, 10, 450, 100, BROWN);
    DrawText("Player default controls:", 190, 20, 20, BLACK);
    DrawText("- ZQSD to move player 1", 210, 50, 20, DARKGRAY);
    DrawText("- Spacebar to plant bomb for player 1", 210, 80, 20, DARKGRAY);

    DrawRectangle(GetScreenWidth() -630, 10, 450, 100, GRAY);
    DrawRectangleLines(GetScreenWidth() -630, 10, 450, 100, DARKGRAY);
    DrawText("Player default controls:", GetScreenWidth() -600, 20, 20, LIGHTGRAY);
    DrawText("- ARROWS to move player 2", GetScreenWidth() -580, 50, 20, WHITE);
    DrawText("- ENTER to plant bomb for player 2", GetScreenWidth() -580, 80, 20, WHITE);
    
    DrawRectangle(170, GetScreenHeight() - 120, 450, 100, PURPLE);
    DrawRectangleLines(170, GetScreenHeight() - 120, 450, 100, PINK);
    DrawText("Player default controls:", 190, GetScreenHeight() - 110, 20, BLACK);
    DrawText("- TFGH to move player 3", 210, GetScreenHeight() - 80, 20, DARKGRAY);
    DrawText("- Y to plant bomb for player 3", 210, GetScreenHeight() - 50, 20, DARKGRAY);

    DrawRectangle(GetScreenWidth() -630, GetScreenHeight() - 120, 450, 100, LIME);
    DrawRectangleLines(GetScreenWidth() -630, GetScreenHeight() - 120, 450, 100, DARKGREEN);
    DrawText("Player default controls:", GetScreenWidth() -600, GetScreenHeight() - 110, 20, LIGHTGRAY);
    DrawText("- IJKL to move player 4", GetScreenWidth() -580, GetScreenHeight() - 80, 20, WHITE);
    DrawText("- U to plant bomb for player 4", GetScreenWidth() -580, GetScreenHeight() - 50, 20, WHITE);
    DrawFPS(GetScreenWidth() / 2 - 5, 10);
}

void Hud::drawPause()
{
    DrawRectangle((GetScreenWidth() / 2) - 185, (GetScreenHeight() / 2) - 100, 360, 250, GOLD);
    DrawRectangleLines((GetScreenWidth() / 2) - 185, (GetScreenHeight() / 2) - 100, 360, 250, ORANGE);
    DrawText("PAUSE", (GetScreenWidth() / 2) - 175, (GetScreenHeight() / 2) - 100, 100, RED);
}
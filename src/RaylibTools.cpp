/*
** EPITECH PROJECT, 2021
** indie
** File description:
** HUD
*/

#include "RaylibTools.hpp"

RayT::RayT()
{
}

RayT::~RayT()
{
}

void RayT::drawRectangle(int posx, int posy, int width, int height, Color color)
{
    DrawRectangle(posx, posy, width, height, color);
}

void RayT::drawRectangleLines(int posx, int posy, int width, int height, Color color)
{
    DrawRectangleLines(posx, posy, width, height, color);
}

Vector2 RayT::getMousePosition()
{
    return(GetMousePosition());
}

void RayT::drawText(const char *text, int posx, int posy, int font, Color color)
{
    DrawText(text, posx, posy, font, color);

}

bool RayT::isKeyPressed(int key)
{
    return(IsKeyPressed(key));
}

bool RayT::isKeyReleased(int key)
{
    return(IsKeyReleased(key));
}

void RayT::clearBackground(Color color)
{
    ClearBackground(color);
}


void RayT::beginDrawing()
{
    BeginDrawing();
}

void RayT::endDrawing()
{
    EndDrawing();
}

void RayT::setExitKey(int key)
{
    SetExitKey(key);
}

int RayT::getScreenWidth()
{
    return (GetScreenWidth());
}

int RayT::getScreenHeight()
{
    return (GetScreenHeight());
}

void RayT::hideCursor()
{
    HideCursor();
}
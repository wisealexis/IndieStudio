/*
** EPITECH PROJECT, 2021
** texture
** File description:
** indie
*/

#include "MouseEngine.hpp"

MouseEngine::MouseEngine(const char *pathTexture, const char*pathAudio, float sizex, float sizez)
{
    Image menuTitle = LoadImage(pathTexture);
    ImageResize(&menuTitle, sizex, sizez);
    _texture = LoadTextureFromImage(menuTitle);
    _sound = LoadSound(pathAudio);
}

MouseEngine::~MouseEngine()
{
    UnloadTexture(_texture);
    UnloadSound(_sound);
}

void MouseEngine::drawMouse()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        PlaySound(_sound);
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        HideCursor();
        DrawTexture(_texture, GetMousePosition().x - 25, GetMousePosition().y - 25, WHITE);
    }
    if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
        ShowCursor();
}

void MouseEngine::setVolume(float volume)
{
    SetSoundVolume(_sound, volume);
}

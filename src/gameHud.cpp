/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** gameHud
*/

#include "main.hpp"

void help_menu(std::vector<Player *> players, Camera3d *Camera, Hud *hud)
{
    hud->drawHelp();
    for (int i = 0; i < 4; i++)
        players[i]->drawPlayerName(Camera->getCamera());
}

void pause_game(ButtonEngine *button_save, ButtonEngine *button_quit, Hud *hud, RayT *rayt, MouseEngine *mouse)
{
    Vector2 mousePoint = rayt->getMousePosition();
    rayt->drawText("Hold left mouse button to start drawing !", rayt->getScreenWidth()/2 - 430, 50, 40, WHITE);
    button_save->isClicked(mousePoint);
    button_quit->isClicked(mousePoint);
    hud->drawPause();
    button_quit->ButtonDraw();
    button_save->ButtonDraw();
    mouse->drawMouse();
}

int game_hud(bool isHelp, AudioEngine *AudioMenu, std::vector<Player *> players, Camera3d *Camera, Hud *hud, RayT *rayt)
{
    if (rayt->isKeyPressed(KEY_P))
        AudioMenu->toggleMusic();
    if (rayt->isKeyReleased(KEY_TAB))
        isHelp = !isHelp;
    if (isHelp)
        help_menu(players, Camera, hud);
    return (isHelp);
}
/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <raylib.h>
#include <rlgl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>

#include "Window.hpp"
#include "AudioEngine.hpp"
#include "BlockEngine.hpp"
#include "Camera3d.hpp"
#include "Player.hpp"
#include "ButtonEngine.hpp"
#include "ImageEngine.hpp"
#include "PercentEngine.hpp"
#include "Settings.hpp"
#include "CheckFiles.hpp"
#include "HUD.hpp"
#include "RaylibTools.hpp"
#include "MouseEngine.hpp"

typedef struct moving_square
{
    Vector3 WallPositions;
    Vector3 WallSizes;
}moving_squares;

int check_files();
int game(AudioEngine *AudioMenu, bool load, Settings *setting, RayT *rayt);
int what_to_draw(int nb_lines, int nb_clmn, char **map, moving_squares *my_square, BlockEngine *modelm, BlockEngine *modelb ,BlockEngine *modelg, int my_time, AudioEngine *explosound,  BlockEngine *modelbomb);
int game_hud(bool isHelp, AudioEngine * AudioMenu, std::vector<Player *> players, Camera3d *Camera, Hud *hud, RayT *rayt);
void pause_game(ButtonEngine *button_save, ButtonEngine *button_quit, Hud *hud, RayT *rayt, MouseEngine *mouse);
int savemap(char **map, int nb_lines, int nb_clmn, std::vector<Player *> player);
int load_map(char **map, int nb_clmn, int nb_lines, std::vector<Player *> players);
int fill_map(char **map, int nb_clmn, int nb_lines, Settings *setting);
char **init_map(int nb_lines, int nb_clmn, std::string myText);

#endif /* !MAIN_HPP_ */
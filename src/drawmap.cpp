/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** drawmap
*/

#include "main.hpp"

int draw_square_1(struct moving_square *my_square, int i, int j, BlockEngine *model)
{
    my_square->WallPositions = {i * 2.0f, 0.0f, j * 2.0f};
    my_square->WallSizes = {2.0f, 2.0f, 2.0f};
    model->BlockDraw(my_square->WallPositions);
    return (0);
}

void draw_map(struct moving_square *my_square, int i, int j, BlockEngine *model)
{
    my_square->WallPositions = {i * 2.0f, -2.0f, j * 2.0f};
    my_square->WallSizes = {2.0f, 2.0f, 2.0f};
    model->BlockDraw(my_square->WallPositions);
}

void draw_bomb(struct moving_square *my_square, int i, int j, BlockEngine *model,  BlockEngine *modelbomb,  char **map)
{
    my_square->WallPositions = {i * 2.0f, 0.0f, j * 2.0f};
    my_square->WallSizes = {i * 2.0f, -2.0f, j * 2.0f};
    if (map[j][i] % 5 == 0)
        modelbomb->DrawBomb(my_square->WallPositions, ((float)map[j][i] - 96) / 780.0 + 0.066);
    else
        modelbomb->DrawBomb2(my_square->WallPositions, ((float)map[j][i] - 96) / 780.0 + 0.066);
    model->BlockDraw(my_square->WallSizes);
}

void draw_explosion(struct moving_square *my_square, int i, int j, BlockEngine *model, BlockEngine *modelbomb, char **map)
{
    my_square->WallPositions = {i * 2.0f, 0.0f, j * 2.0f};
    my_square->WallSizes = {i * 2.0f, -2.0f, j * 2.0f};
    modelbomb->DrawExplo(my_square->WallPositions, 0.031 / (map[j][i] - 122));
    model->BlockDraw(my_square->WallSizes);
}

void lunch_bomb(char **map, int nb_clmn, int posx, int posz, AudioEngine *explosound)
{
    explosound->playSound();
    bool stopxa = false;
    bool stopxb = false;
    bool stopza = false;
    bool stopzb = false;
    map[posz][posx] = '{';
    for (int i = posx; i != posx + 3 && map[posz][i] != '#' && stopxa == false; i++) {
        if (map[posz][i] == 'B')
            stopxa = true;
        if (map[posz][i] >='a' && map[posz][i] <= 'z')
            lunch_bomb(map, nb_clmn, i, posz, explosound);
        map[posz][i] = '{';
    }
    for (int i = posx; i != posx - 3 && map[posz][i] != '#' && stopxb == false; i--) {
        if (map[posz][i] == 'B')
            stopxb = true;
        if (map[posz][i] >='a' && map[posz][i] <= 'z')
            lunch_bomb(map, nb_clmn, i, posz, explosound);
        map[posz][i] = '{';
    }
    for (int i = posz; i != posz + 3 && map[i][posx] != '#' && stopza == false; i++) {
        if (map[i][posx] == 'B')
            stopza = true;
        if (map[i][posx] >='a' && map[i][posx] <= 'z')
            lunch_bomb(map, nb_clmn, posx, i, explosound);
        map[i][posx] = '{';
    }
    for (int i = posz; i != posz - 3 && map[i][posx] != '#' && stopzb == false; i--) {
        if (map[i][posx] == 'B')
            stopzb = true;
        if (map[i][posx] >='a' && map[i][posx] <= 'z')
            lunch_bomb(map, nb_clmn, posx, i, explosound);
        map[i][posx] = '{';
    }
}

int what_to_draw(int nb_lines, int nb_clmn, char **map, moving_squares *my_square, BlockEngine *modelm, BlockEngine *modelb ,BlockEngine *modelg, int my_time, AudioEngine *explosound, BlockEngine *modelbomb)
{
    my_time++;
    int k = 0;
    for (int i = 0; i != nb_lines; i++) {
        for (int j = 0; j != nb_clmn; j++) {
            if (my_time == 5 && map[i][j] >='a' && map[i][j] <= '}')
                    map[i][j] += 1;
            if (map[i][j] == 'z')
                lunch_bomb(map, nb_clmn, j, i, explosound);
            if (map[i][j] == '~')
                map[i][j] = ' ';
            if (map[i][j] == '#')
                draw_square_1(&(my_square[k]), j, i, modelm);
            else if (map[i][j] == 'B') {
                draw_square_1(&(my_square[k]), j, i, modelb);
                draw_map(&(my_square[k]), j, i, modelg);
            }
            else if (map[i][j] == ' ')
                draw_map(&(my_square[k]), j, i, modelg);
            else if (map[i][j] >='a' && map[i][j] <= 'z')
                draw_bomb(&(my_square[k]), j, i, modelg, modelbomb, map);
            else if (map[i][j] >= '{' && map[i][j] <= '}')
                draw_explosion(&(my_square[k]), j, i, modelg, modelbomb, map);
        }
        k++;
    }
    if (my_time == 5)
        my_time = 0;
    return (my_time);
}
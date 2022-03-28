/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** drawmap
*/

#include "main.hpp"

int savemap(char **map, int nb_lines, int nb_clmn, std::vector<Player *> players)
{
    for (int i = 0; i < 4; i++)
        if (!players[i]->getisdead())
            map[players[i]->getactposz()][players[i]->getactposx()] = i + 49;

    std::ofstream ofs;
    ofs.open("map.txt", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i != nb_lines ; i++) {
        for (int j = 0; j != nb_clmn ; j++)
            ofs << map[i][j];
        ofs << std::endl;
    }
    ofs.close();
    return (10);
}

int load_map(char **map, int nb_clmn, int nb_lines, std::vector<Player *> players)
{
    int nb_alive = 0;
    for (int i = 0; i != nb_clmn; i++) {
        map[0][i] = '#';
        map[nb_lines - 1][i] = '#';
    }
    for (int i = 0; i != nb_lines; i++) {
        map[i][0] = '#';
        map[i][nb_clmn - 1] = '#';
    }
    for (int i = 0; i != nb_lines; i++)
        for (int j = 0; j != nb_clmn; j++) {
            if (map[i][j] < 'a' && map[i][j] != 'B' && map[i][j] != '#' && map[i][j] != ' '  && map[i][j] != '1'  && map[i][j] != '2'  && map[i][j] != '3'  && map[i][j] != '4')
                map[i][j] = ' ';
            for (int k = 0; k < 4; k++)
                if (map[i][j] == k + 49) {
                    players[k]->change_pos(j, i);
                    map[i][j] = ' ';
                    players[k]->setisdead(false);
                }
        }
    for (int i = 0; i < 4; i++)
        if (!players[i]->getisdead())
            nb_alive++;
    if (nb_alive < 2)
        return (1);
    return (0);
}

int fill_map(char **map, int nb_clmn, int nb_lines, Settings *setting)
{
    int rand_value = 0;

    for (int i = 0; i != nb_clmn; i++) {
        map[0][i] = '#';
        map[nb_lines - 1][i] = '#';
    }
    for (int i = 0; i != nb_lines; i++) {
        map[i][0] = '#';
        map[i][nb_clmn - 1] = '#';
    }
    for (int i = 0; i != nb_lines; i++)
        for (int j = 0; j != nb_clmn; j++) {
            rand_value = GetRandomValue(0, 99);
            if (map[i][j] != '#')
                if (rand_value < setting->getDensity())
                    map[i][j] = 'B';
                else
                    map[i][j] = ' ';
        }

    map[1][1] = ' ';
    map[2][1] = ' ';
    map[1][2] = ' ';
    map[nb_lines - 2][nb_clmn - 2] = ' ';
    map[nb_lines - 3][nb_clmn - 2] = ' ';
    map[nb_lines - 2][nb_clmn - 3] = ' ';
    map[1][nb_clmn - 2] = ' ';
    map[2][nb_clmn - 2] = ' ';
    map[1][nb_clmn - 3] = ' ';
    map[nb_lines - 2][1] = ' ';
    map[nb_lines - 3][1] = ' ';
    map[nb_lines - 2][2] = ' ';
    if (setting->getNbPlayer() == 2) {
        map[nb_lines - 2][nb_clmn - 2] = 's';
        map[nb_lines - 2][1] = 's';
    }

    return (0);
}

char **init_map(int nb_lines, int nb_clmn, std::string myText)
{
    char **map = (char **)malloc(sizeof(char *) * nb_lines);
    int k = 0;
    for (int z = 0; z != nb_lines; z++)
        map[z] = (char *)malloc(sizeof(char) * nb_clmn);
    map[1][1] = 'i';
    for (int i = 0; i != nb_lines; i++)
    {
        for (int j = 0; myText[k] != '\n'; j++)
        {
            map[i][j] = myText[k];
            k++;
        }
        k++;
    }
    return (map);
}
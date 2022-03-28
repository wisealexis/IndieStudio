/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** CheckFiles
*/

#include "CheckFiles.hpp"

CheckFiles::CheckFiles()
{
}

CheckFiles::~CheckFiles()
{
}

int CheckFiles::Check(std::string sources[], int nb_files)
{
    int j = 0;
    bool missing = true;

    while(!IsKeyPressed(KEY_ESCAPE) && missing) {
        j = 0;
        BeginDrawing();
        DrawText("The binary is not where it is supposed to be or this files are missing:                     PRESS ESC TO QUIT", 10.0f, 10.0f, 30.0f, RED);
        ClearBackground(BLACK);
        for (int i = 0; i < nb_files; i++) {
            std::ifstream f(sources[i]);
            if(!f.good()){
                DrawText(sources[i].c_str(), 50.0f, 50.0f + 20.0 * j, 15.0f, WHITE);
                j++;
            }
        }
        EndDrawing();
        if (j == 0)
            missing = false;
    }
    if (missing)
        return (-1);
    return (0);

}

/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "main.hpp"

void endgame(ButtonEngine *button_quit, std::vector<Player *> players, RayT *rayt, MouseEngine *mouse)
{
    rayt->drawRectangle((rayt->getScreenWidth() / 2) - 185, (rayt->getScreenHeight() / 2) - 200, 360, 300, GOLD);
    rayt->drawRectangleLines((rayt->getScreenWidth() / 2) - 185, (rayt->getScreenHeight() / 2) - 200, 360, 300, ORANGE);
    Vector2 mousePoint = rayt->getMousePosition();
    button_quit->isClicked(mousePoint);
    button_quit->ButtonDraw();
    for (int i = 0; i < 4; i++)
        if (!players[i]->getisdead())
            rayt->drawText(players[i]->getplayername(), (rayt->getScreenWidth() / 2) - 175, (rayt->getScreenHeight() / 2) - 200, 80, RED);
    if (players[0]->getisdead() && players[1]->getisdead() && players[2]->getisdead() && players[3]->getisdead())
        rayt->drawText("No one", (rayt->getScreenWidth() / 2) - 175, (rayt->getScreenHeight() / 2) - 200, 80, RED);
    rayt->drawText("Won !", (rayt->getScreenWidth() / 2) - 120, (rayt->getScreenHeight() / 2) - 100, 80, RED);
    mouse->drawMouse();
}

bool dead_players(std::vector<Player *> players)
{
    int players_dead = 0;

    for (int i = 0; i < 4; i++)
        if (players[i]->getisdead())
            players_dead++;
    if (players_dead >= 3)
        return (true);
    return (false);
}

int game(AudioEngine *AudioMenu, bool load, Settings *setting, RayT *rayt)
{
    std::ifstream MyReadFile;
    MyReadFile.open("map.txt");
    if (!MyReadFile)
        return (11);
    Hud *hud = new Hud();
    MouseEngine *mouse = new MouseEngine("assets/texture/hitmarker.png", "assets/music/hitmarker.mp3", 50, 50);
    BlockEngine *modelm = new BlockEngine("assets/texture/Metal.png");
    BlockEngine *modelb = new BlockEngine("assets/texture/break.png");
    BlockEngine *modelg = new BlockEngine("assets/texture/map.png");
    BlockEngine *modelbomb = new BlockEngine("assets/texture/map.png");
    modelbomb->createFromModel("assets/models/tnt/textures/palette_blanche.png", "assets/models/tnt/scene.gltf", "assets/models/tnt/textures/palette_baseColor.png");
    modelbomb->createExplo("assets/models/bomberman_fire/textures/Fire_baseColor.png", "assets/models/bomberman_fire/scene.gltf");
    AudioEngine *Grass = new AudioEngine();
    AudioEngine *explosound = new AudioEngine();
    Grass->setSoundTrack("assets/music/grass.mp3");
    explosound->setSoundTrack("assets/music/bomb-sound.mp3");
    Grass->ChangeSoundVolume(((float)setting->getSoundVol())/100);
    explosound->ChangeSoundVolume(((float)setting->getSoundVol())/100);
    AudioMenu->setMusicTrack("assets/music/bomberman-game.mp3");
    AudioMenu->playMusic();
    AudioMenu->changeMusicVolume(((float)setting->getGameVol())/100);
    Camera3d *Camera = new Camera3d();
    Camera->setMode(CAMERA_FREE);
    ButtonEngine *button_quit = new ButtonEngine("assets/texture/quit_button.png", (rayt->getScreenWidth() / 2) - 130, (rayt->getScreenHeight() / 2.0f) + 10.0f);
    ButtonEngine *button_save = new ButtonEngine("assets/texture/save_and_quit_button.png", (rayt->getScreenWidth() / 2) - 130, (rayt->getScreenHeight() / 2.0f) + 80.0f);

    std::string myTemp;
    std::string myText;
    int nb_lines = 0;
    size_t nb_clmn = 0;
    
    while (getline(MyReadFile, myTemp))
    {
        if (myTemp.length() > nb_clmn)
            nb_clmn = myTemp.length();
        nb_lines++;
        myText = myText + myTemp;
        myText = myText + "\n";
    }
    MyReadFile.close();
    if (nb_lines < 6 || nb_clmn < 6)
        return (11);

    std::vector<Player *> players;
    Player *player1 = new Player("assets/models/steve/textures/02_-_Default_baseColor.png", "assets/models/steve/scene.gltf", 1.0, 1.0, "Player 1", "assets/texture/steve_head.png");
    player1->assign_keys(KEY_W, KEY_S, KEY_A, KEY_D, KEY_SPACE);
    players.push_back(player1);
    Player *player2 = new Player("assets/models/Skeleton/textures/02_-_Default_baseColor.png", "assets/models/Skeleton/scene.gltf", nb_clmn - 2, 1.0, "Player 2", "assets/texture/skeletton_head.png");
    player2->assign_keys(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER);
    players.push_back(player2);
    Player *player3 = new Player("assets/models/Creeper/textures/02_-_Default_baseColor.png", "assets/models/Creeper/scene.gltf", 1.0, nb_lines - 2, "Player 3", "assets/texture/creeper_head.png");
    player3->assign_keys(KEY_T, KEY_G, KEY_F, KEY_H, KEY_Y);
    players.push_back(player3);
    Player *player4 = new Player("assets/models/Zombie/textures/02_-_Default_baseColor.png", "assets/models/Zombie/scene.gltf", nb_clmn - 2, nb_lines - 2, "Player 4", "assets/texture/zombie_head.png");
    player4->assign_keys(KEY_I, KEY_K, KEY_J, KEY_L, KEY_U);
    players.push_back(player4);

    char **map = init_map(nb_lines, nb_clmn, myText);
    if (!load) {
        fill_map(map, nb_clmn, nb_lines, setting);
        for (int i = 0; i < 4; i++)
            players[i]->setisdead(false);
    }
    else if (load_map(map, nb_clmn, nb_lines, players) == 1)
        return (11);
    moving_squares *my_square = (moving_squares *)malloc(sizeof(moving_squares) * (nb_clmn * nb_lines));

    bool isHelp = false;
    bool isPause = false;
    int my_time = 0;
    while (button_quit->getBtnState() != 4 && button_save->getBtnState() != 4) {
        AudioMenu->update();
        Camera->update();
        if (rayt->isKeyPressed(KEY_ESCAPE) && !dead_players(players))
            isPause = !isPause;
        if (!isPause) {
            if (!dead_players(players))
                for (int i = 0; i < 4; i++)
                    players[i]->movement_input(map, Grass);
            Camera->begin3dMode();
            rayt->clearBackground(BLACK);
            my_time = what_to_draw(nb_lines, nb_clmn, map, my_square, modelm, modelb, modelg, my_time, explosound, modelbomb);
            if (!dead_players(players)) {
                for (int i = 0; i < 4; i++) {
                    players[i]->placeBomb(map, setting->getInfBombs());
                    rayt->hideCursor();
                }
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (!players[i]->getisdead() && !players[j]->getisdead() && i != j)
                            players[j]->testCollision(players[i]->getPos(), players[i]->getSize());
                for (int i = 0; i < 4; i++)
                    players[i]->move_player();
            }
            for (int i = 0; i < 4; i++)
                players[i]->draw_player(isHelp);
            Camera->end3dMode();
        }
            if (isPause)
                pause_game(button_save, button_quit, hud, rayt, mouse);
        if (dead_players(players))
            endgame(button_quit, players, rayt, mouse);
        isHelp = game_hud(isHelp, AudioMenu, players, Camera, hud, rayt);
        for (int i = 0; i < 4; i++)
            players[i]->drawPlayerLogo(i + 1);
        rayt->endDrawing();
    }
    if (button_save->getBtnState() == 4)
        savemap(map, nb_lines, nb_clmn, players);
    for (int z = 0; z != nb_lines; z++)
        free(map[z]);
    free(map);
    return (10);
}
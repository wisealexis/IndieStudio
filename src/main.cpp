/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** menu
*/

#include "main.hpp"

int settings(AudioEngine * AudioMenu, ImageEngine *background, Settings *setting, RayT *rayt, MouseEngine *mouse)
{
    PercentEngine *button_mastvol = new PercentEngine("assets/texture/master_volume.png", 50.0f, rayt->getScreenHeight() / 2.0f - 260.0f, setting->getMastVol());
    PercentEngine *button_soundvol = new PercentEngine("assets/texture/sound_volume.png", 50.0f, rayt->getScreenHeight() / 2.0f - 190.0f, setting->getSoundVol());
    PercentEngine *button_gamevol = new PercentEngine("assets/texture/game_volume.png", 50.0f, rayt->getScreenHeight() / 2.0f -120.0f, setting->getGameVol());
    PercentEngine *button_menuvol = new PercentEngine("assets/texture/menu_volume.png", 50.0f, rayt->getScreenHeight() / 2.0f - 50.0f, setting->getMenuVol());
    PercentEngine *button_density = new PercentEngine("assets/texture/map_density.png", 50.0f, rayt->getScreenHeight() / 2.0f + 20.0f, setting->getDensity());
    ButtonEngine *button_2p = new ButtonEngine("assets/texture/two_players_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 160.0f);
    ButtonEngine *button_4p = new ButtonEngine("assets/texture/four_players_button.png", 330.0f, rayt->getScreenHeight() / 2.0f + 160.0f);
    ButtonEngine *button_nbbomb = new ButtonEngine("assets/texture/nb_bombs_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 230.0f);
    button_nbbomb->setBtnAction(!setting->getInfBombs());
    ButtonEngine *button_quit = new ButtonEngine("assets/texture/back_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 370.0f);
    ImageEngine *one = new ImageEngine("assets/texture/one.png", 330.0f, rayt->getScreenHeight() / 2.0f + 230.0f, 54.0, 54.0);
    ImageEngine *infinite = new ImageEngine("assets/texture/infinity.png", 330.0f, rayt->getScreenHeight() / 2.0f + 230.0f, 54.0, 54.0);
    
    Vector2 mousePoint = {0.0f, 0.0f};
    while (button_quit->getBtnState() != 4 && !rayt->isKeyPressed(KEY_ESCAPE))
    {
        mousePoint = rayt->getMousePosition();
        AudioMenu->update();
        if (rayt->isKeyPressed(KEY_P))
            AudioMenu->toggleMusic();
        button_mastvol->isClicked(mousePoint);
        button_soundvol->isClicked(mousePoint);
        button_gamevol->isClicked(mousePoint);
        button_menuvol->isClicked(mousePoint);
        button_density->isClicked(mousePoint);
        button_quit->isClicked(mousePoint);
        button_2p->isClicked(mousePoint);
        button_4p->isClicked(mousePoint);
        button_nbbomb->isClicked(mousePoint);
        if (button_soundvol->ispressed())
            mouse->setVolume(((float)button_soundvol->getPercent())/100);
        if (button_menuvol->ispressed())
            AudioMenu->changeMusicVolume(((float)button_menuvol->getPercent())/100);
        if (button_mastvol->ispressed())
            AudioMenu->setMasterVolume(((float)button_mastvol->getPercent())/100);
        if (button_2p->getBtnState() == 4)
            setting->setNbPlayer(2);
        if (button_4p->getBtnState() == 4)
            setting->setNbPlayer(4);
        
        rayt->beginDrawing();
        rayt->clearBackground(RAYWHITE);
        background->ImageDraw();
        button_soundvol->ButtonDraw();
        button_mastvol->ButtonDraw();
        button_gamevol->ButtonDraw();
        button_menuvol->ButtonDraw();
        button_density->ButtonDraw();
        button_2p->ButtonDraw();
        button_4p->ButtonDraw();
        button_nbbomb->ButtonDraw();
        if (button_nbbomb->getBtnAction())
            one->ImageDraw();
        if (!button_nbbomb->getBtnAction())
            infinite->ImageDraw();
        button_quit->ButtonDraw();
        mouse->drawMouse();
        rayt->endDrawing();
    }
    if (!button_nbbomb->getBtnAction())
            setting->setInfBombs(true);
    if (button_nbbomb->getBtnAction())
            setting->setInfBombs(false);
    setting->setSoundVol(button_soundvol->getPercent());
    setting->setMastVol(button_mastvol->getPercent());
    setting->setMenuVol(button_menuvol->getPercent());
    setting->setGameVol(button_mastvol->getPercent());
    setting->setDensity(button_density->getPercent());
    return (0);
}

int credits(AudioEngine * AudioMenu, ImageEngine *background, RayT *rayt, MouseEngine *mouse)
{
    ImageEngine *credit = new ImageEngine("assets/texture/credits.png", 50, 0, rayt->getScreenWidth(), rayt->getScreenHeight());
    ButtonEngine *button_quit = new ButtonEngine("assets/texture/back_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 400.0f);
    Vector2 mousePoint = {0.0f, 0.0f};
    while (button_quit->getBtnState() != 4 && !IsKeyPressed(KEY_ESCAPE))
    {
        if (rayt->isKeyPressed(KEY_P))
            AudioMenu->toggleMusic();
        mousePoint = rayt->getMousePosition();
        AudioMenu->update();
        button_quit->isClicked(mousePoint);
        rayt->beginDrawing();
        rayt->clearBackground(RAYWHITE);
        background->ImageDraw();
        credit->ImageDraw();
        button_quit->ButtonDraw();
        mouse->drawMouse();
        rayt->endDrawing();
    }
    return (0);
}

void maperror(RayT *rayt)
{
    rayt->drawRectangle(15, 15, 1600, 90, WHITE);
    rayt->drawRectangleLines(15, 15, 1600, 90, MAROON);
    rayt->drawText("map.txt does not exist or has a problem!", 20, 20, 75, RED);
}

void my_scale(ImageEngine *title, bool scale)
{
    if (scale)
        title->changeScale(title->getScale() + 0.01);
    else
        title->changeScale(title->getScale() - 0.01);
}

int menu(AudioEngine *AudioMenu, bool map_error, Settings *setting, RayT *rayt)
{
    AudioMenu->setMusicTrack("assets/music/bomberman-menu.mp3");
    AudioMenu->playMusic();
    AudioMenu->changeMusicVolume(((float)setting->getMenuVol())/100);
    ImageEngine *background = new ImageEngine("assets/texture/Bomberman.png", 0, 0, rayt->getScreenWidth(), rayt->getScreenHeight());
    ImageEngine *title = new ImageEngine("assets/texture/Super_Bomberman_Logo.png", 400.0, 100.0, 600.0, 300.0);
    MouseEngine *mouse = new MouseEngine("assets/texture/hitmarker.png", "assets/music/hitmarker.mp3", 50, 50);
    std::vector<ButtonEngine *> buttons;

    ButtonEngine *button_new = new ButtonEngine("assets/texture/new_game_button.png", 50.0f, rayt->getScreenHeight() / 2.0f - 50.0f);
    buttons.push_back(button_new);
    ButtonEngine *button_load = new ButtonEngine("assets/texture/load_game_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 20.0f);
    buttons.push_back(button_load);
    ButtonEngine *button_settings = new ButtonEngine("assets/texture/settings_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 90.0f);
    buttons.push_back(button_settings);
    ButtonEngine *button_credits = new ButtonEngine("assets/texture/credits_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 160.0f);
    buttons.push_back(button_credits);
    ButtonEngine *button_exit = new ButtonEngine("assets/texture/exit_button.png", 50.0f, rayt->getScreenHeight() / 2.0f + 230.0f);
    buttons.push_back(button_exit);
    if (!button_new || !button_load || !button_settings || !button_credits || ! button_exit || !background || !title)
        return (99);

    Vector2 mousePoint = {0.0f, 0.0f};
    bool is_scale = true;

    while (button_new->getBtnState() != 4 && button_exit->getBtnState() != 4 && button_load->getBtnState() != 4 && !rayt->isKeyPressed(KEY_ESCAPE))
    {
        AudioMenu->update();
        mousePoint = rayt->getMousePosition();
        for (int i = 0; i < 5; i++)
            buttons[i]->isClicked(mousePoint);
        if (button_credits->getBtnState() == 4)
            credits(AudioMenu, background, rayt, mouse);
        if (button_settings->getBtnState() == 4)
            settings(AudioMenu, background, setting, rayt, mouse);
        if (rayt->isKeyPressed(KEY_P))
            AudioMenu->toggleMusic();

        rayt->beginDrawing();
        rayt->clearBackground(RAYWHITE);
        background->ImageDraw();
        if (title->getScale() > 1.3 || title->getScale() < 1.0)
            is_scale = !is_scale;
        my_scale(title, is_scale);
        title->ImageDraw();
        for (int i = 0; i < 5; i++)
            buttons[i]->ButtonDraw();    
        if (map_error)
            maperror(rayt);
        mouse->drawMouse();
        rayt->endDrawing();
    }
    if (button_new->getBtnState() == 4)
        return (20);
    if (button_load->getBtnState() == 4)
        return (21);
    return (99);
}

int state_of_game(int state, AudioEngine *AudioMenu, Settings *setting, RayT *rayt)
{
    while (state != 99) {
    if (state == 10)
        state = menu(AudioMenu, false, setting, rayt);
    else if (state == 11)
        state = menu(AudioMenu, true, setting, rayt);
    else if (state == 20)
        state = game(AudioMenu, false, setting, rayt);
    else if (state == 21)
        state = game(AudioMenu, true, setting, rayt);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 1) {
        std::cout << "\e[0;31mYou don't need any argument !\x1b[0m" << std::endl;
        return (84);
    }
    RayT *rayt = new RayT();
    Window *Win = new Window();
    Win->init();
    Win->toggleFullscreen();
    rayt->setExitKey(KEY_DELETE);
    if (check_files() == -1)
        return (84);
    Settings *setting = new Settings();
    AudioEngine *AudioMenu = new AudioEngine();
    AudioMenu->init();
    state_of_game(10, AudioMenu, setting, rayt);
    Win->close();
    return (0);
}
/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** buttonEngine
*/

#include <raylib.h>
#include <iostream>

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

class Settings {
    public:
        Settings();
        ~Settings();
        int getMastVol();
        void setMastVol(int mastvol);
        int getGameVol();
        void setGameVol(int gamevol);
        int getMenuVol();
        void setMenuVol(int menuvol);
        int getDensity();
        void setDensity(int density);
        int getNbPlayer();
        void setNbPlayer(int nbplayers);
        bool getInfBombs();
        void setInfBombs(bool infbomb);
        int getSoundVol();
        void setSoundVol(int soundvol);

    protected:
    private:
    int _soundvol;
    int _mastvol;
    int _gamevol;
    int _menuvol;
    int _density;
    int _nbplayer;
    bool _infbombs;

};

#endif /* !SETTINGS_HPP_ */

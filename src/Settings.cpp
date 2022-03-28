/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include "Settings.hpp"

Settings::Settings()
{
    _soundvol = 100;
    _mastvol = 100;
    _gamevol = 100;
    _menuvol = 50;
    _density = 40;
    _nbplayer = 4;
    _infbombs = false;
}

Settings::~Settings()
{
}

int Settings::getMastVol()
{
    return (_mastvol);
}

void Settings::setMastVol(int mastvol)
{
    _mastvol = mastvol;
}

int Settings::getGameVol()
{
    return (_gamevol);
}

void Settings::setGameVol(int gamevol)
{
    _gamevol = gamevol;
}

int Settings::getMenuVol()
{
    return (_menuvol);
}

void Settings::setMenuVol(int menuvol)
{
    _menuvol = menuvol;
}

int Settings::getDensity()
{
    return (_density);
}

void Settings::setDensity(int density)
{
    _density = density;
}

int Settings::getNbPlayer()
{
    return (_nbplayer);
}

void Settings::setNbPlayer(int nbplayers)
{
    _nbplayer = nbplayers;
}

bool Settings::getInfBombs()
{
    return (_infbombs);
}

void Settings::setInfBombs(bool infbomb)
{
    _infbombs = infbomb;
}

int Settings::getSoundVol()
{
    return (_soundvol);
}

void Settings::setSoundVol(int soundvol)
{
    _soundvol = soundvol;
}
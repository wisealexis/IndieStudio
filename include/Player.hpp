/*
** EPITECH PROJECT, 2021
** $
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <raylib.h>
#include <iostream>
#include <math.h>

#include "AudioEngine.hpp"

class Player {      
    public:
        Player(const char* texture_path, const char* model_path,float posx, float posz, std::string, const char *logo_path);
        ~Player();
        void assign_keys(int keyup, int keydown, int keyleft, int keyright, int _keybomb);
        void movement_input(char ** map, AudioEngine *Grass);
        void change_scale(float scale);
        void change_rotation(Vector3 rotation);
        void change_pos(float posx, float posz);
        void move_player();
        void draw_player(int hitbox);
        int getrposx();
        int getrposz();
        int getrtargx();
        int getrtargz();
        int getkeybomb();
        int getactposx();
        int getactposz();
        bool getisdead();
        void setisdead(bool isdead);
        const char *getplayername();
        void drawPlayerLogo(int pos);
        void drawPlayerName(Camera Camera);
        void testCollision(Vector3 p2pos, Vector3 p2size);
        Vector3 getPos();
        Vector3 getSize();
        void placeBomb(char **map, bool inf);
        int _posbombx;
        int _posbombz;

    protected:
    private:
        Texture2D _playerlogo;
        Texture2D _crossdead;
        std::string _playername;
        Texture2D _texture;
        Model _model;
        Vector3 _playerPosition;
        Vector3 _playerRotation;
        Vector3 _playerScale;
        Vector3 _playerSize;
        float _playerAngle;
        float _targetx;
        float _targetz;
        int _rposx;
        int _rposz;
        int _rtargx;
        int _rtargz;
        int _keyup;
        int _keydown;
        int _keyleft;
        int _keyright;
        int _keybomb;
        int _actposx;
        int _actposz;
        bool _isdead;
        Vector2 _playerscreensposition;
        bool _collision;
};

#endif /* !PLAYER_HPP_ */

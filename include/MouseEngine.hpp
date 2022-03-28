/*
** EPITECH PROJECT, 2021
** MapTexture
** File description:
** hpp
*/

#ifndef MOUSEENGINE_HPP_
#define MOUSEENGINE_HPP_

#include "raylib.h"

class MouseEngine {
    public:
        MouseEngine(const char *pathTexture, const char*pathAudio, float sizex, float sizez);
        ~MouseEngine();
        void drawMouse();
        void setVolume(float volume);

    protected:
    private:
        Texture2D _texture;
        Sound _sound;
};

#endif /* !BLOCKENGINE_HPP_ */

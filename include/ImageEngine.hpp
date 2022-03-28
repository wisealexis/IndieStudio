/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** buttonEngine
*/

#include <raylib.h>
#include <iostream>

#ifndef IMAGEENGINE_HPP_
#define IMAGEENGINE_HPP_

class ImageEngine {
    public:
        ImageEngine(const char *path, float posx, float posz, float sizex, float sizez);
        ~ImageEngine();
        void ImageDraw();
        float getScale();
        float getRotation();
        void changeScale(float scale);
        void changeRotation(float rotation);

    protected:
    private:
        Texture2D _texture;
        Vector2 _position;
        float _rotation;
        float _scale;
};

#endif /* !IMAGEENGINE_HPP_ */

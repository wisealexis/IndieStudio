/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include"ImageEngine.hpp"

ImageEngine::ImageEngine(const char *path, float posx, float posz, float sizex, float sizez)
{
    Image menuTitle = LoadImage(path);
    ImageResize(&menuTitle, sizex, sizez);
    _texture = LoadTextureFromImage(menuTitle);
    _position = {posx, posz};
    _rotation = 0;
    _scale = 1;
}

ImageEngine::~ImageEngine()
{
    UnloadTexture(_texture);
}

void ImageEngine::ImageDraw()
{
    DrawTextureEx(_texture, _position, _rotation, _scale, WHITE);
}

float ImageEngine::getRotation()
{
    return (_rotation);
}

float ImageEngine::getScale()
{
    return (_scale);
}

void ImageEngine::changeRotation(float rotation)
{
    _rotation = rotation;
}

void ImageEngine::changeScale(float scale)
{
    _scale = scale;
}



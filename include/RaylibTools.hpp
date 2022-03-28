/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** buttonEngine
*/

#include <raylib.h>
#include <iostream>

#ifndef RAYLIBTOOLS_HPP_
#define RAYLIBTOOLS_HPP_

class RayT {
    public:
        RayT();
        ~RayT();
        void drawRectangle(int posx, int posy, int width, int height, Color color);
        void drawRectangleLines(int posx, int posy, int width, int height, Color color);
        Vector2 getMousePosition();
        void drawText(const char* text, int posx, int posy, int font, Color color);
        bool isKeyPressed(int key);
        bool isKeyReleased(int key);
        void clearBackground(Color color);
        void beginDrawing();
        void endDrawing();
        void setExitKey(int key);
        int getScreenWidth();
        int getScreenHeight();
        void hideCursor();

    protected:
    private:
};

#endif /* !HUD_HPP_ */

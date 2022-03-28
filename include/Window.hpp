/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <raylib.h>
#include <iostream>
#include <string>
#include <cstring>

class Window {
    public:
        Window();
        Window(int width, int height, std::string name);
        ~Window();
        void init();
        void toggleFullscreen();
        bool shouldClose();
        void close();

    protected:

    private:
        int _width;
        int _height;
        std::string _name;
};

#endif /* !WINDOW_HPP_ */

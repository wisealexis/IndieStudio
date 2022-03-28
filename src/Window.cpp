/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Window
*/

#include "Window.hpp"

Window::Window() :  _width(1920),
                    _height (1080),
                    _name("Indie Studio")
{
}

Window::Window(int width, int height, std::string name) :   _width(width),
                                                            _height(height),
                                                            _name(name)
{
}

Window::~Window()
{
}

void Window::init()
{
    InitWindow(_width, _height, _name.c_str());
    SetTargetFPS(60);
}

void Window::toggleFullscreen()
{
    ToggleFullscreen();
}

bool Window::shouldClose()
{
    return WindowShouldClose();
}

void Window::close()
{
    CloseWindow();
}
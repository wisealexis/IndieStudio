/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include "ButtonEngine.hpp"

ButtonEngine::ButtonEngine(std::string path, float posx, float posz)
{
    _button = LoadTexture(path.c_str());
    _frameHeight = (float)_button.height / 3;
    _sourceRec = {0, 0, (float)_button.width, _frameHeight};
    _btnBounds = {posx, posz, (float)_button.width, _frameHeight};
    _btnState = 0;
    _btnAction = false;
}

ButtonEngine::~ButtonEngine()
{
    UnloadTexture(_button);
}

void ButtonEngine::ButtonInit(std::string path, float posx, float posz)
{
}

void ButtonEngine::ButtonDraw()
{
    DrawTextureRec(_button, _sourceRec, Vector2{_btnBounds.x, _btnBounds.y}, WHITE);
}

int ButtonEngine::getBtnState()
{
    return (_btnState);
}

void ButtonEngine::updateBtnSrcRec()
{
    _sourceRec.y = _btnState * _frameHeight;
}

void ButtonEngine::isClicked(Vector2 mousePoint)
{
    if (CheckCollisionPointRec(mousePoint, _btnBounds))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnState = 2;
        else
            _btnState = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            _btnState = 4;
            _btnAction = !_btnAction;
        }
    }
    else
        _btnState = 0;
    updateBtnSrcRec();
}

bool ButtonEngine::getBtnAction()
{
    return (_btnAction);
}

void ButtonEngine::setBtnAction(bool action)
{
    _btnAction = action;
}
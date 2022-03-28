/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include "PercentEngine.hpp"

PercentEngine::PercentEngine(const char *path, float posx, float posz, int percent)
{
    Image Mess = LoadImage(path);
    _textureMess = LoadTextureFromImage(Mess);
    _positionMess = {posx, posz};

    _buttonSub = LoadTexture("assets/texture/minus_button.png");
    _frameHeightSub = (float)_buttonSub.height / 3;
    _sourceRecSub = {0, 0, (float)_buttonSub.width, _frameHeightSub};
    _btnBoundsSub = {posx + 280, posz, (float)_buttonSub.width, _frameHeightSub};
    _btnStateSub = 0;
    
    Image Perc = LoadImage("assets/texture/percent.png");
    _texturePerc = LoadTextureFromImage(Perc);
    _positionPerc = {posx + 340, posz};

    _buttonAdd = LoadTexture("assets/texture/plus_button.png");
    _frameHeightAdd = (float)_buttonAdd.height / 3;
    _sourceRecAdd = {0, 0, (float)_buttonAdd.width, _frameHeightAdd};
    _btnBoundsAdd = {posx + 598, posz, (float)_buttonAdd.width, _frameHeightAdd};
    _btnStateAdd = 0;

    _positionText = {posx + 420, posz +5};

    if (percent > 100)
        _percent = 100;
    else if (percent < 0)
        _percent = 0;
    else _percent = percent;
}

PercentEngine::~PercentEngine()
{
    UnloadTexture(_textureMess);
    UnloadTexture(_buttonSub);
    UnloadTexture(_texturePerc);
    UnloadTexture(_buttonAdd);
}

void PercentEngine::ButtonDraw()
{
    DrawTextureRec(_buttonSub, _sourceRecSub, Vector2{_btnBoundsSub.x, _btnBoundsSub.y}, WHITE);
    DrawTexture(_textureMess, _positionMess.x , _positionMess.y, WHITE);
    DrawTexture(_texturePerc, _positionPerc.x, _positionPerc.y, WHITE);
    DrawTextureRec(_buttonAdd, _sourceRecAdd, Vector2{_btnBoundsAdd.x, _btnBoundsAdd.y}, WHITE);
    std::string s = std::to_string(_percent);
    DrawText(s.c_str(), _positionText.x, _positionText.y, 50, WHITE);
}

void PercentEngine::updateBtnSrcRec()
{
    _sourceRecSub.y = _btnStateSub * _frameHeightSub;
    _sourceRecAdd.y = _btnStateAdd * _frameHeightAdd;
}

void PercentEngine::isClicked(Vector2 mousePoint)
{
    if (CheckCollisionPointRec(mousePoint, _btnBoundsSub))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnStateSub = 2;
        else
            _btnStateSub = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            _btnStateSub = 4;
            _percent -= 5;
        }
    }
    else
        _btnStateSub = 0;

    if (CheckCollisionPointRec(mousePoint, _btnBoundsAdd))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            _btnStateAdd = 2;
        else
            _btnStateAdd = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            _btnStateAdd = 4;
            _percent += 5;
        }
    }
    else
        _btnStateAdd = 0;
    if (_percent > 100)
        _percent = 100;
    else if (_percent < 0)
        _percent = 0;
    updateBtnSrcRec();
}

int PercentEngine::getPercent()
{
    return(_percent);
}

bool PercentEngine::ispressed()
{
    if (_btnStateSub == 4 || _btnStateAdd == 4)
        return (true);
    return (false);
}
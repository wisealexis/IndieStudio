/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** buttonEngine
*/

#include <raylib.h>
#include <iostream>
#include <sstream>

#ifndef PERCENTENGINE_HPP_
#define PERCENTENGINE_HPP_

class PercentEngine {
    public:
        PercentEngine(const char *path1, float posx, float posz, int percent);
        ~PercentEngine();
        void ButtonDraw();
        void updateBtnSrcRec();
        void isClicked(Vector2 mousePoint);
        int getPercent();
        bool ispressed();

    protected:
    private:
        int _percent;
        Vector2 _positionText;

        int _btnStateSub;
        float _frameHeightSub;
        Texture2D _buttonSub;
        Rectangle _sourceRecSub;
        Rectangle _btnBoundsSub;

        int _btnStateAdd;
        float _frameHeightAdd;
        Texture2D _buttonAdd;
        Rectangle _sourceRecAdd;
        Rectangle _btnBoundsAdd;

        Texture2D _textureMess;
        Vector2 _positionMess;
        Texture2D _texturePerc;
        Vector2 _positionPerc;
};

#endif /* !PERCENTENGINE_HPP_ */

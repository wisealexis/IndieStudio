/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** buttonEngine
*/

#include <raylib.h>
#include <iostream>

#ifndef BUTTONENGINE_HPP_
#define BUTTONENGINE_HPP_

class ButtonEngine {
    public:
        ButtonEngine(std::string path, float posx, float posz);
        ~ButtonEngine();
        void ButtonInit(std::string path, float posx, float posz);
        void ButtonDraw();
        int getBtnState();
        void updateBtnSrcRec();
        void isClicked(Vector2 mousePoint);
        bool getBtnAction();
        void setBtnAction(bool action);


    protected:
    private:
        int _btnState;
        bool _btnAction;
        float _frameHeight;
        Texture2D _button;
        Rectangle _sourceRec;
        Rectangle _btnBounds;
};

#endif /* !BUTTONENGINE_HPP_ */

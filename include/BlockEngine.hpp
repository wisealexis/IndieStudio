/*
** EPITECH PROJECT, 2021
** MapTexture
** File description:
** hpp
*/

#ifndef BLOCKENGINE_HPP_
#define BLOCKENGINE_HPP_

#include "raylib.h"

class BlockEngine {
    public:
        BlockEngine(const char *path);
        ~BlockEngine();
        void createFromModel(const char *texture1, const char *model1, const char *texture2);
        void createExplo(const char *texture, const char *model);
        void BlockDraw(Vector3 position);
        void DrawBomb(Vector3 position, float scale);
        void DrawBomb2(Vector3 position, float scale);
        void DrawExplo(Vector3 position, float scale);

    protected:
    private:
        Model _model;
        Model _model2;
        Model _model3;
        Vector3 _BlockRotation = {0.0f, 1.0f, 0.0f};
        float _BlockAngle = 0;
        Vector3 _BlockScale = {0.1f, 0.1f, 0.1f};
        Vector3 _BlockScale3 = {0.1f, 0.1f, 0.1f};
};

#endif /* !BLOCKENGINE_HPP_ */

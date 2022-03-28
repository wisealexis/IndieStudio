/*
** EPITECH PROJECT, 2021
** texture
** File description:
** indie
*/

#include "BlockEngine.hpp"

BlockEngine::BlockEngine(const char *path)
{
    Texture2D texture = LoadTexture(path);
    Mesh mesh = GenMeshCube(2.0, 2.0, 2.0);
    _model = LoadModelFromMesh(mesh);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    _BlockRotation = {0.0, 0.0, 0.0};
    _BlockAngle = 0.0;
    _BlockScale = {0.1, 0.1, 0.1};
}

BlockEngine::~BlockEngine()
{
    UnloadModel(_model);
    UnloadModel(_model2);
    UnloadModel(_model3);
}

void BlockEngine::createFromModel(const char *texture1, const char *model1, const char *texture2)
{
    _model = LoadModel(model1);
    Texture2D texture2D1 = LoadTexture(texture1);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture2D1;

    _model2 = LoadModel(model1);
    Texture2D texture2D2 = LoadTexture(texture2);
    _model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture2D2;
}

void BlockEngine::createExplo(const char *texture, const char *model)
{
    _model3 = LoadModel(model);
    Texture2D texture2D2 = LoadTexture(texture);
    _model3.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture2D2;
}

void BlockEngine::BlockDraw(Vector3 position)
{
    DrawModel(_model, position, 1.0f, WHITE);
}

void BlockEngine::DrawBomb(Vector3 position, float scale)
{
    _BlockScale = {scale, scale, scale};
    position = {position.x, position.y - 2, position.z};
    DrawModelEx(_model, position, _BlockRotation, _BlockAngle, _BlockScale, WHITE);
}

void BlockEngine::DrawBomb2(Vector3 position, float scale)
{
    _BlockScale = {scale, scale, scale};
    position = {position.x, position.y - 2, position.z};
    DrawModelEx(_model2, position, _BlockRotation, _BlockAngle, _BlockScale, WHITE);
}

void BlockEngine::DrawExplo(Vector3 position, float scale)
{
    _BlockScale = {scale, scale, scale};
    position = {position.x, position.y - 2, position.z};
    DrawModelEx(_model3, position, _BlockRotation, _BlockAngle, _BlockScale, WHITE);
}
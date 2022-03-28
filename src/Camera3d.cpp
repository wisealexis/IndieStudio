/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Camera3d
*/

#include "Camera3d.hpp"

Camera3d::Camera3d() :  _position({22.0f, 50.0f, 30.0f}),
                        _target({22.0f, 0.0f, 15.0f}),
                        _fovy(40.0f),
                        _up({0.0f, 1.0f, 0.0f}),
                        _projection(CAMERA_PERSPECTIVE)
{
    _camera.position = _position;
    _camera.target = _target;
    _camera.fovy = _fovy;
    _camera.up = _up;
    _camera.projection = _projection;
}

Camera3d::Camera3d(Vector3 pos, Vector3 target, float fov) :    _position(pos),
                                                                _target(target),
                                                                _fovy(fov),
                                                                _up({0.0f, 1.0f, 0.0f}),
                                                                _projection(CAMERA_PERSPECTIVE)
{
    _camera.position = _position;
    _camera.target = _target;
    _camera.fovy = _fovy;
    _camera.up = _up;
    _camera.projection = _projection;
}

Camera3d::~Camera3d()
{
}

void Camera3d::update()
{
    UpdateCamera(&_camera);
}

void Camera3d::setMode(int mode)
{
    SetCameraMode(_camera, mode);
}

void Camera3d::begin3dMode()
{
    BeginMode3D(_camera);
}

void Camera3d::end3dMode()
{
    EndMode3D();
}

Camera3D Camera3d::getCamera()
{
    return (_camera);
}
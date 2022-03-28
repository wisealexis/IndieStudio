/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Camera3d
*/

#ifndef Camera3d_HPP_
#define Camera3d_HPP_

#include <raylib.h>

class Camera3d {
    public:
        Camera3d();
        Camera3d(Vector3, Vector3, float);
        ~Camera3d();
        void setMode(int mode);
        void begin3dMode();
        void end3dMode();
        void update();
        Camera3D getCamera();

    protected:
    private:
        Camera3D _camera;
        Vector3 _position;
        Vector3 _target;
        Vector3 _up;
        float _fovy;
        int _projection;
        int _mode;
};

#endif /* !Camera3d_HPP_ */

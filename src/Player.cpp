/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(const char *texture, const char *model, float posx, float posz, std::string playername, const char *logo_path)
{
    _model = LoadModel(model);
    _texture = LoadTexture(texture);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;

    _playerPosition = {2 * posx, 0.0, 2 * posz};
    _playerRotation = {0.0f, 1.0f, 0.0f};
    _playerAngle = 0;
    _playerScale = {0.1f, 0.1f, 0.1f};
    _playerSize = {1.8f, 3.0f, 1.8f};
    _targetx = posx * 2;
    _targetz = posz * 2;
    _isdead = true;
    _playername = playername;
    _collision = false;
    _posbombx = posx;
    _posbombz = posz;

    Image logo = LoadImage(logo_path);
    _playerlogo = LoadTextureFromImage(logo);
    Image cross = LoadImage("assets/texture/cross_dead.png");
    _crossdead = LoadTextureFromImage(cross);
}

Player::~Player()
{
    UnloadTexture(_texture);
    UnloadModel(_model);
    UnloadTexture(_playerlogo);
    UnloadTexture(_crossdead);
}

void Player::change_pos(float posx, float posz)
{
    _playerPosition = {2 * posx, 0.0, 2 * posz};
    _targetx = posx * 2;
    _targetz = posz * 2;
}

void Player::movement_input(char **map, AudioEngine *Grass)
{
    if (!_isdead)
    {
        _rposx = round(_playerPosition.x * 10);
        _rposz = round(_playerPosition.z * 10);
        _rtargx = round(_targetx * 10);
        _rtargz = round(_targetz * 10);

        if (_rposx == _rtargx && _rposz == _rtargz) {
            _actposx = _rtargx / 20;
            _actposz = _rtargz / 20;
        }

        if (map[_actposz][_actposx] >= '{' && map[_actposz][_actposx] <= '}')
            _isdead = true;

        if (IsKeyDown(_keyright) && _rtargx <= _rposx && round(_targetz * 10) == _rposz && !_collision) {
            if (map[_actposz][_actposx + 1] == ' ' || map[_actposz][_actposx + 1] == '{' || map[_actposz][_actposx + 1] == '|' || map[_actposz][_actposx + 1] == '}')
                _targetx += 2.0;
            Grass->playSound();
        }
        if (IsKeyDown(_keyleft) && _rtargx >= _rposx && round(_targetz * 10) == _rposz && !_collision) {
            if (map[_actposz][_actposx - 1] == ' ' || map[_actposz][_actposx - 1] == '{' || map[_actposz][_actposx - 1] == '|' || map[_actposz][_actposx - 1] == '}')
                _targetx -= 2.0;
            Grass->playSound();
        }
        if (IsKeyDown(_keydown) && _rtargz <= _rposz && round(_targetx * 10) == _rposx && !_collision) {
            if (map[_actposz + 1][_actposx] == ' ' || map[_actposz + 1][_actposx] == '{' || map[_actposz + 1][_actposx] == '|' || map[_actposz + 1][_actposx] == '}')
                _targetz += 2.0;
            Grass->playSound();
        }
        if (IsKeyDown(_keyup) && _rtargz >= _rposz && round(_targetx * 10) == _rposx && !_collision) {
            if (map[_actposz - 1][_actposx] == ' ' || map[_actposz - 1][_actposx] == '{' || map[_actposz - 1][_actposx] == '|' || map[_actposz - 1][_actposx] == '}')
                _targetz -= 2.0;
            Grass->playSound();
        }

        _rtargx = round(_targetx * 10);
        _rtargz = round(_targetz * 10);
    }
}

void Player::placeBomb(char **map, bool inf)
{
    if(map[_posbombz][_posbombx] < 'a' || map[_posbombz][_posbombx] > 'z' || inf)
        if (IsKeyDown(_keybomb) && _rposx == _rtargx && _rposz == _rtargz && !_isdead)
            if (map[_actposz][_actposx] < 'a' || map[_actposz][_actposx] > 'z') {
                map[_actposz][_actposx] = 'a';
                _posbombx = _actposx;
                _posbombz = _actposz;
            }
}

void Player::assign_keys(int keyup, int keydown, int keyleft, int keyright, int keybomb)
{
    _keyup = keyup;
    _keydown = keydown;
    _keyleft = keyleft;
    _keyright = keyright;
    _keybomb = keybomb;
}

void Player::move_player()
{
    if (_rposx > _rtargx)
    {
        _playerPosition.x -= 0.2;
        _playerAngle = 270.0;
    }
    else if (_rposx < _rtargx)
    {
        _playerPosition.x += 0.2;
        _playerAngle = 90.0;
    }

    if (_rposz > _rtargz)
    {
        _playerPosition.z -= 0.2;
        _playerAngle = 180.0;
    }
    else if (_rposz < _rtargz)
    {
        _playerPosition.z += 0.2;
        _playerAngle = 0.0;
    }
    if (_collision && _rtargx == _rposx && _rtargz == _rposz)
        _collision = false;
}

void Player::drawPlayerName(Camera3D camera)
{
    if (!_isdead)
    {
        _playerscreensposition = GetWorldToScreen(Vector3{_playerPosition.x, _playerPosition.y + 2.5f, _playerPosition.z}, camera);
        if (!_collision)
            DrawText(_playername.c_str(), (int)_playerscreensposition.x - MeasureText(_playername.c_str(), 20) / 2, (int)_playerscreensposition.y - 20, 20, WHITE);
        else
            DrawText(_playername.c_str(), (int)_playerscreensposition.x - MeasureText(_playername.c_str(), 20) / 2, (int)_playerscreensposition.y - 20, 20, RED);
    }
}

void Player::draw_player(int hitbox)
{
    if (!_isdead)
        DrawModelEx(_model, _playerPosition, _playerRotation, _playerAngle, _playerScale, WHITE);
    if (hitbox == 1 && !_isdead) {
        DrawCubeWires(_playerPosition, _playerSize.x, _playerSize.y, _playerSize.z, WHITE);
        if (_collision)
            DrawCubeWires(_playerPosition, _playerSize.x, _playerSize.y, _playerSize.z, RED);
    }
}

void Player::drawPlayerLogo(int pos)
{
    Vector2 position = {0.0, 0.0};

    if (pos == 1)
        position = {10.0, 10.0};
    else if (pos == 2)
        position = {GetScreenWidth() - 170.0f, 10.0};
    else if (pos == 3)
        position = {10.0, GetScreenHeight() - 170.0f};
    else if (pos == 4)
        position = {GetScreenWidth() - 170.0f, GetScreenHeight() - 170.0f};
    DrawTextureEx(_playerlogo, position, 0.0, 1.0, WHITE);
    if (_isdead)
        DrawTextureEx(_crossdead, position, 0.0, 1.0, WHITE);
}

void Player::testCollision(Vector3 p2pos, Vector3 p2size)
{
    if (CheckCollisionBoxes(
            BoundingBox{Vector3{_playerPosition.x - _playerSize.x / 2,
                                _playerPosition.y - _playerSize.y / 2,
                                _playerPosition.z - _playerSize.z / 2},
                        Vector3{_playerPosition.x + _playerSize.x / 2,
                                _playerPosition.y + _playerSize.y / 2,
                                _playerPosition.z + _playerSize.z / 2}},
            BoundingBox{Vector3{p2pos.x - p2size.x / 2,
                                p2pos.y - p2size.y / 2,
                                p2pos.z - p2size.z / 2},
                        Vector3{p2pos.x + p2size.x / 2,
                                p2pos.y + p2size.y / 2,
                                p2pos.z + p2size.z / 2}}))
        _collision = true;

    if (_collision) {
        _targetx = _actposx * 2;
        _targetz = _actposz * 2;
    }
}

int Player::getrposx()
{
    return (_rposx);
}
int Player::getrposz()
{
    return (_rposz);
}

int Player::getrtargx()
{
    return (_rtargx);
}
int Player::getrtargz()
{
    return (_rtargz);
}

int Player::getkeybomb()
{
    return (_keybomb);
}

void Player::change_scale(float scale)
{
    _playerScale = {scale, scale, scale};
}

void Player::change_rotation(Vector3 rotation)
{
    _playerRotation = rotation;
}

int Player::getactposx()
{
    return (_actposx);
}
int Player::getactposz()
{
    return (_actposz);
}

bool Player::getisdead()
{
    return (_isdead);
}
void Player::setisdead(bool isdead)
{
    _isdead = isdead;
}

const char *Player::getplayername()
{
    return (_playername.c_str());
}

Vector3 Player::getPos()
{
    return(_playerPosition);
}

Vector3 Player::getSize()
{
    return(_playerSize);
}
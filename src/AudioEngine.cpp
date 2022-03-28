/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include "AudioEngine.hpp"

AudioEngine::AudioEngine() : _isPlaying(false)
{
}

AudioEngine::~AudioEngine()
{
    UnloadMusicStream(_track);
    UnloadSound(_sound);
}

void AudioEngine::init()
{
    InitAudioDevice();
    setMasterVolume(0.5);
}

void AudioEngine::setMusicTrack(std::string path)
{
    _track = LoadMusicStream(path.c_str());    
}

void AudioEngine::update()
{
    UpdateMusicStream(_track);
}

void AudioEngine::playMusic()
{
    PlayMusicStream(_track);
    _isPlaying = true;
}

void AudioEngine::pauseMusic()
{
    PauseMusicStream(_track);
    _isPlaying = false;
}

void AudioEngine::resumeMusic()
{
    ResumeMusicStream(_track);
    _isPlaying = true;
}

void AudioEngine::toggleMusic()
{
    if (_isPlaying == true)
        pauseMusic();
    else
        resumeMusic();
}

void AudioEngine::changeMusicVolume(float volume)
{
    SetMusicVolume(_track, volume);
}

void AudioEngine::setMasterVolume(float volume)
{
    SetMasterVolume(volume);
}

void AudioEngine::ChangeSoundVolume(float volume)
{
    SetSoundVolume(_sound, volume);
}

void AudioEngine::setSoundTrack(const char* path)
{
    _sound = LoadSound(path);
}

void AudioEngine::playSound()
{
    PlaySound(_sound);
}
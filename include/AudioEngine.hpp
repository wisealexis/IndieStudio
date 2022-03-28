/*
** EPITECH PROJECT, 2021
** indie
** File description:
** AudioEngine
*/

#include <raylib.h>
#include <iostream>

#ifndef AUDIOENGINE_HPP_
#define AUDIOENGINE_HPP_

class AudioEngine {
    public:
        AudioEngine();
        ~AudioEngine();
        void init();
        void setMusicTrack(std::string path);
        void update();
        void playMusic();
        void pauseMusic();
        void resumeMusic();
        void toggleMusic();
        void changeMusicVolume(float volume);
        void setMasterVolume(float volume);
        void setSoundTrack(const char* path);
        void ChangeSoundVolume(float volume);
        void playSound();

    protected:
    private:
        Music _track;
        Sound _sound;
        bool _isPlaying;
};

#endif /* !AUDIOENGINE_HPP_ */
#pragma once 

#include <iostream>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

class Audio
{
public:
    Audio(const char* p_path);
    void play();
    void closeAudio();
    void freeAudio();
private:
    Mix_Music *music;
};
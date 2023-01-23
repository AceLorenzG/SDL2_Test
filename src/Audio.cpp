#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "Audio.hpp"

Audio::Audio(const char* p_path)
    :music(NULL)
{
    music = Mix_LoadMUS(p_path);
    if(music == NULL)
    {
        std::cerr << "Mix_LoadMUS Error: " << Mix_GetError() << std::endl;
    }
}

void Audio::play()
{
    Mix_PlayMusic(music, 1);
}

void Audio::closeAudio()
{
    Mix_CloseAudio();
}

void Audio::freeAudio()
{
    Mix_FreeMusic(music);
}
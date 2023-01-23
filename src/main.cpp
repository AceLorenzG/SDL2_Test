/*Memory Leak??*/



#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "WindowsRenderer.hpp"
#include "Audio.hpp"

int main(int argc, char *argv[])
{
    if(SDL_Init(IMG_INIT_JPG) != 0)
    {
        std::cout << "Img jpg failed" << SDL_GetError() << std::endl;
        return 1;
    }
    if(SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        std::cerr << "SDL_INIT_AUDIO Error: " << SDL_GetError() << std::endl;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
    }
    WindowsRender window("Baby", 1280, 720);
    SDL_Texture *mahalko;
    mahalko = window.Loadtexture("../720x814.jpg");
    bool running = true;
    Audio song("C:/Users/GALLO/Documents/Cplus/try/Tonight(MP3_128K).mp3");
    song.play();
    SDL_Event event;
    while(running)
    {
        //controls input
        while(SDL_PollEvent(&event))
        {
            if(Mix_PlayingMusic() != 1)
                event.type = SDL_QUIT;
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        window.clearRenderer();
        window.render(mahalko);
        window.display();
    }
    song.freeAudio();
    song.closeAudio();
    window.cleanUp();
    SDL_Quit();
    return 0;
}
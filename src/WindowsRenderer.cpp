#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "WindowsRenderer.hpp"

WindowsRender::WindowsRender(const char* _title, int _width, int _hight)
{
    window = NULL;
    renderer = NULL;
    window = SDL_CreateWindow(_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _hight, 0);
    if(window == NULL)
    {
        std::cout << "Failed To Create Window Error: " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL)
    {
        std::cout << "Failed To create renderer Error: " << SDL_GetError() << std::endl;
    }
}
SDL_Texture *WindowsRender::Loadtexture(const char* _filepath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, _filepath);
    if(texture == NULL)
    {
        std::cout << "failed to load texture Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}
void WindowsRender::cleanUp()
{
    SDL_DestroyWindow(window);
}
void WindowsRender::clearRenderer()
{
    SDL_RenderClear(renderer);
}
void WindowsRender::render(SDL_Texture *_texture)
{
    //what part of the picture
    SDL_Rect Source;
    Source.x = 0;
    Source.y = 0;
    Source.h = 814;
    Source.w = 720;

    //size of the picture
    SDL_Rect Dest;
    Dest.x = 40;
    Dest.y = 40;
    Dest.h = 868/2;
    Dest.w = 720/2;
    SDL_RenderCopy(renderer, _texture, &Source, &Dest);
}
void WindowsRender::display()
{
    SDL_RenderPresent(renderer);
}
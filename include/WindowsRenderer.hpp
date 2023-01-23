#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class WindowsRender
{
public:
    WindowsRender(const char* _title, int _width, int _hight);
    SDL_Texture *Loadtexture(const char* _filePath);
    //clean up
    void cleanUp();
    void clearRenderer();
    void render(SDL_Texture *_texture);
    void display();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
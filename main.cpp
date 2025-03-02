#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>

#define WINX 400
#define WINY 400

int main()
{
    SDL2pp::SDL sdl(SDL_INIT_VIDEO);
	SDL2pp::Window window("sdl_circle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINX, WINY, SDL_WINDOW_RESIZABLE);
	SDL2pp::Renderer render(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    render.SetDrawBlendMode(SDL_BLENDMODE_BLEND);

    render.SetDrawColor({0,0,0});
    render.Clear();

    SDL_Delay(1000);

    return 0;
}

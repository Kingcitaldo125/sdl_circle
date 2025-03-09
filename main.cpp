#include <cmath>

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

    constexpr int midx = WINX / 2;
    constexpr int midy = WINY / 2;
    constexpr int circle_rad = 50;

    render.SetDrawColor({0,255,0});
    render.DrawPoint(midx, midy);

    render.SetDrawColor({255,0,0});

    for(int i = 0; i < 360; ++i)
    {
        const int x = cos(i) * circle_rad;
        const int y = sin(i) * circle_rad;

        const int end_x = x + midx;
        const int end_y = y + midy;

        render.DrawPoint(end_x, end_y);
    }

    render.Present();

    SDL_Delay(5000);

    return 0;
}

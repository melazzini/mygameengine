#include <iostream>
#include <SDL2/SDL.h>

#include "utils.hpp"

auto renderer_creator = [](SDL_Window *wnd)
{
    auto r = SDL_CreateRenderer(wnd,
                                -1, // index of the driver screen where you want to render,  -1 the first one supporting the requested flags
                                0   // no flags
    );

    if (!r)
    {
        std::cerr << "error initializing sdl renderer" << std::endl;
        throw std::runtime_error{"error!"};
    }

    return r;
};

auto window_creator = []()
{
    auto w = SDL_CreateWindow(nullptr, // NO TITLE
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              600, 400,
                              SDL_WINDOW_BORDERLESS);

    if (!w)
    {
        std::cerr << "error initializing sdl window" << std::endl;
        throw std::runtime_error{"error!"};
    }

    return w;
};
std::unique_ptr<void, void (*)(void *)> RenderEngine::_sdl{
    ([]()
     {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << SDL_GetError() << std::endl;
        abort();
    }
    return nullptr; })(),
    ([](void *)
     { SDL_Quit(); })};

std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> RenderEngine::_backendEngine = std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>{nullptr, [](SDL_Renderer *) {}};
std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> RenderEngine::_backendWindow = std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{nullptr, [](SDL_Window *) {}};

gsl::not_null<SDL_Renderer *> RenderEngine::backendEngine()
{
    if (_backendEngine)
    {
        return _backendEngine.get();
    }
    else
    {
        initializeBackend();
        return _backendEngine.get();
    }
}

void RenderEngine::initializeBackend()
{
    _backendWindow = makeUnique<SDL_Window>(
        window_creator, ([](SDL_Window *sdlWindow)
                         {
                            if(sdlWindow)
                            {
                                SDL_DestroyWindow(sdlWindow);
                            } 
                            }));

    _backendEngine = makeUnique<SDL_Renderer>(
        renderer_creator, ([](SDL_Renderer *sdlRenderer)
                           {if(sdlRenderer)SDL_DestroyRenderer(sdlRenderer); }),
        _backendWindow.get());
}
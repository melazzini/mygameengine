#ifndef _UTILS_HPP_
#define _UTILS_HPP_
#include "gsl/gsl"
#include <memory>

template <typename T, typename C, typename D, typename... Args>
std::unique_ptr<T, D> makeUnique(C creator, D deleter, Args... args)
{
    return std::unique_ptr<T, D>(creator(args...), deleter);
}

struct SDL_Renderer;
struct SDL_Window;

struct RenderEngine
{
    static gsl::not_null<SDL_Renderer *> backendEngine();

private:
    static std::unique_ptr<void, void(*)(void *)> _sdl;
    static std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> _backendEngine;
    static std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> _backendWindow;

    static void initializeBackend();
};

// using RenderEngine

#endif // !_UTILS_HPP_
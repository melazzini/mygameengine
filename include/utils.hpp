#ifndef _UTILS_HPP_
#define _UTILS_HPP_
#include "gsl/gsl"
#include <memory>

struct Position
{
    double x{};
    double y{};
};

struct Size
{
    double w{};
    double h{};
};

inline bool operator==(const Position &left, const Position &right)
{
    return (left.x == right.x) && (left.y == right.y);
}

inline Position operator+(const Position &left, const Position &right)
{
    return Position{left.x + right.x, left.y + right.y};
}

struct Color
{
    int r;
    int g;
    int b;
    int alpha;

    static const Color Black;
    static const Color White;
    static const Color Blue;
    static const Color Red;
    static const Color Green;
};

inline bool operator==(const Color &left, const Color &right)
{
    return (left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.alpha == right.alpha);
}

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

    virtual void presentScene();

private:
    static std::unique_ptr<void, void (*)(void *)> _sdl;
    static std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)> _backendEngine;
    static std::unique_ptr<SDL_Window, void (*)(SDL_Window *)> _backendWindow;

    static void initializeBackend();
};

// using RenderEngine

#endif // !_UTILS_HPP_
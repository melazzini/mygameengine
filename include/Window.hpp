#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
#include"utils.hpp"
#include"Renderer.hpp"

struct Color
{
    int r;
    int g;
    int b;
    int alpha;
};

struct Window
{
    void clear(gsl::not_null<Renderer *> renderer, const Color color)
    {
    }

    void present(gsl::not_null<Renderer *> renderer)
    {
    }
};

#endif // !_WINDOW_HPP_
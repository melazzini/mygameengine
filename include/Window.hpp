#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
#include "utils.hpp"

struct Renderer;

struct Color
{
    int r;
    int g;
    int b;
    int alpha;

    static const Color Black;
};

inline bool operator==(const Color &left, const Color &right)
{
    return (left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.alpha == right.alpha);
}

struct IWindowPrimitive
{
    virtual void clearWithRenderer(gsl::not_null<Renderer *> renderer, const Color &color) = 0;

    virtual void presentWithRenderer(gsl::not_null<Renderer *> renderer) = 0;
};

struct IWindow
{
    virtual gsl::not_null<IWindowPrimitive *> primitive() const = 0;
};

struct Window : IWindow
{
    virtual gsl::not_null<IWindowPrimitive *> primitive() const override
    {
    }
};

#endif // !_WINDOW_HPP_
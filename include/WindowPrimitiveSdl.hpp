#ifndef _WINDOWPRIMITIVESDL_HPP
#define _WINDOWPRIMITIVESDL_HPP

#include "IWindowPrimitive.hpp"

struct WindowPrimitiveSdl : IWindowPrimitive
{
    virtual void clearWithRenderer(gsl::not_null<IRenderer *> renderer, const Color &color);
};

#endif // !_WINDOWPRIMITIVESDL_HPP
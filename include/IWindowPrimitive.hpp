#ifndef _IWINDOWPRIMITIVE_HPP_
#define _IWINDOPRIMITIVE_HPP_

#include "utils.hpp"

struct IRenderer;

struct IWindowPrimitive
{
    virtual void clearWithRenderer(gsl::not_null<IRenderer *> renderer, const Color &color) = 0;
};


#endif // !_IWINDOWPRIMITIVE_HPP_

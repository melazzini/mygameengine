#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include "IWindow.hpp"

struct Window : IWindow
{
    virtual gsl::not_null<IWindowPrimitive *> primitive() const override
    {
    }
};

#endif // !_WINDOW_HPP_
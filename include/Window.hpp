#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include "IWindow.hpp"

struct Window : IWindow
{
    Window(gsl::not_null<IWindowPrimitive *> primitive)
        : m_primitive{primitive}
    {
    }

    virtual gsl::not_null<IWindowPrimitive *> primitive() const override
    {
        return m_primitive;
    }

private:
    gsl::not_null<IWindowPrimitive *> m_primitive;
};

#endif // !_WINDOW_HPP_
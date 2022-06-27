#ifndef _IWINDOW_HPP_
#define _IWINDOW_HPP_

#include "IWindowPrimitive.hpp"

struct IWindow
{
    virtual gsl::not_null<IWindowPrimitive *> primitive() const = 0;
};

#endif // !_IWINDOW_HPP_
#ifndef _IIMAGE_HPP_
#define _IIMAGE_HPP_

#include "gsl/gsl"

struct Renderer;

struct IImage
{
    virtual bool empty() const = 0;
    virtual void renderPrimitive(gsl::not_null<Renderer *> renderer) const = 0;
};

#endif // !_IIMAGE_HPP_
#ifndef _IIMAGE_HPP_
#define _IIMAGE_HPP_

#include "gsl/gsl"

struct Renderer;

struct IImage
{
    virtual bool empty() const = 0;
    virtual gsl::not_null<IImagePrimitive *> primitive() const = 0;
};

#endif // !_IIMAGE_HPP_
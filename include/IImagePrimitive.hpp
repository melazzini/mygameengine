#ifndef _IIMAGEPRIMITIVE_HPP_
#define _IIMAGEPRIMITIVE_HPP_

#include "gsl/gsl"
#include <filesystem>

struct Renderer;

struct IImagePrimitive
{
    virtual void loadWithRenderer(gsl::not_null<Renderer *> renderer, const std::filesystem::path &path) = 0;

    virtual void paintWithRenderer(gsl::not_null<Renderer *> renderer) = 0;

    virtual bool empty() const = 0;
};

#endif // _IIMAGEPRIMITIVE_HPP_
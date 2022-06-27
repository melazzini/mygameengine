#ifndef _IIMAGEPRIMITIVE_HPP_
#define _IIMAGEPRIMITIVE_HPP_

#include "gsl/gsl"
#include <filesystem>

struct IRenderer;

struct IImagePrimitive
{
    virtual void loadWithRenderer(gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path) = 0;

    virtual void paintWithRenderer(gsl::not_null<IRenderer *> renderer) = 0;

    virtual bool empty() const = 0;
};

#endif // _IIMAGEPRIMITIVE_HPP_
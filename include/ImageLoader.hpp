#ifndef _IMAGELOADER_HPP_
#define _IMAGELOADER_HPP_

#include "IImageLoader.hpp"
#include "IImagePrimitive.hpp"
#include <stdexcept>

struct ImageLoader : IImageLoader
{
    ImageLoader(gsl::not_null<Renderer *> renderer)
        : m_renderer{renderer}
    {
    }

    virtual void load(gsl::not_null<IImagePrimitive *> primitive, const std::filesystem::path &path) const override
    {
        primitive->loadWithRenderer(m_renderer, path);
        if (primitive->empty())
        {
            throw std::runtime_error{"The image is empty!"};
        }
    }

private:
    gsl::not_null<Renderer *> m_renderer;
};

#endif // _IMAGELOADER_HPP_

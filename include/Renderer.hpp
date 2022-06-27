#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "Image.hpp"
#include "IRenderer.hpp"
#include "IImagePrimitive.hpp"

struct Renderer : IRenderer
{
    Renderer(gsl::not_null<RenderEngine *> engine)
        : m_engine{engine}
    {
    }

    void render(gsl::not_null<IImage *> image)
    {
        if (image->empty())
        {
            throw std::runtime_error{"empty image cannot be drawn!"};
        }
        else
        {
            image->primitive()->paintWithRenderer(this);
            // image->renderPrimitive(this);
        }
    }

    gsl::not_null<RenderEngine *> engine() const override { return m_engine; }

private:
    gsl::not_null<RenderEngine *> m_engine;
};

#endif // !_RENDERER_HPP_

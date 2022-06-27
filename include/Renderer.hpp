#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "Image.hpp"
#include "IRenderer.hpp"
#include "IImagePrimitive.hpp"
#include "Window.hpp"

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
        }
    }

    gsl::not_null<RenderEngine *> engine() const override { return m_engine; }

    void clearWindow(gsl::not_null<IWindow *> wnd, const Color &color)
    {
        wnd->primitive()->clearWithRenderer(this, color);
    }

    void present() const
    {
        m_engine->presentScene();
    }

private:
    gsl::not_null<RenderEngine *> m_engine;
};

#endif // !_RENDERER_HPP_

#ifndef _IRENDERER_HPP_
#define _IRENDERER_HPP_
#include "utils.hpp"

struct IRenderer
{
    virtual gsl::not_null<RenderEngine *> engine() const = 0;
};

#endif // !_IRENDERER_HPP_

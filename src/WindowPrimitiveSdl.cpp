#include <SDL2/SDL.h>

#include "WindowPrimitiveSdl.hpp"
#include "IRenderer.hpp"

void WindowPrimitiveSdl::clearWithRenderer(gsl::not_null<IRenderer *> renderer, const Color &color)
{
    SDL_SetRenderDrawColor(renderer.get()->engine()->backendEngine(), color.r, color.g, color.b, color.alpha);
    SDL_RenderClear(renderer.get()->engine()->backendEngine());
}
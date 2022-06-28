#ifndef _IMAGEPRIMITIVESDL_HPP_
#define _IMAGEPRIMITIVESDL_HPP_

#include "IImagePrimitive.hpp"
#include <SDL2/SDL.h>

struct SDL_Texture;

struct ImagePrimitiveSdl : IImagePrimitive
{
    ImagePrimitiveSdl();

    virtual void loadWithRenderer(gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path_) override;

    virtual void paintWithRenderer(gsl::not_null<IRenderer *> renderer) override;

    virtual bool empty() const override;

    virtual void setPosition(const Position &pos) override;
    virtual Position position() const override;

private:
    SDL_RendererFlip m_spriteFlip = SDL_FLIP_NONE;
    SDL_Rect m_srcRectangle;
    SDL_Rect m_destRectangle;
    SDL_RendererFlip flip;
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)> m_texture;
};

#endif // !_IMAGEPRIMITIVESDL_HPP_
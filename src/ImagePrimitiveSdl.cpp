#include "ImagePrimitiveSdl.hpp"
#include "Renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>

ImagePrimitiveSdl::ImagePrimitiveSdl()
    : m_texture{nullptr, [](SDL_Texture *) {}}
{
    m_srcRectangle.x = 0;
    m_srcRectangle.y = 0;
    m_srcRectangle.w = 50;
    m_srcRectangle.h = 50;

    m_destRectangle = m_srcRectangle;
}

void ImagePrimitiveSdl::loadWithRenderer(gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path)
{
    auto surface{IMG_Load(path.c_str())};
    auto texture{SDL_CreateTextureFromSurface(renderer->engine()->backendEngine(), surface)};
    SDL_FreeSurface(surface);
    m_texture = std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)>(texture, [](SDL_Texture *texture_)
                                                                      { SDL_DestroyTexture(texture_); });
}

void ImagePrimitiveSdl::setPosition(const Position &pos)
{
    m_destRectangle.x = static_cast<int>(pos.x);
    m_destRectangle.y = static_cast<int>(pos.y);
}

static const double ZeroDegrees = 0;

static const SDL_Point *RotationAroundCenter = nullptr;

void ImagePrimitiveSdl::paintWithRenderer(gsl::not_null<IRenderer *> renderer)
{
    auto ok = SDL_RenderCopyEx(renderer->engine()->backendEngine(), m_texture.get(), &m_srcRectangle, &m_destRectangle, ZeroDegrees, RotationAroundCenter, m_spriteFlip);
}

bool ImagePrimitiveSdl::empty() const
{
    return m_texture == nullptr;
}

Position ImagePrimitiveSdl::position() const
{
    return Position{static_cast<double>(m_destRectangle.x),
                    static_cast<double>(m_destRectangle.y)};
}
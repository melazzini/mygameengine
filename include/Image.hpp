#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "ImageLoader.hpp"
#include "IImage.hpp"
#include "utils.hpp"

/**
 * @brief This is an image-primitive (IImagePrimitive) manager.
 *
 * @details The user should use this class to work (render, change size, ...)
 * with primitive images.
 *
 */
struct Image : IImage
{
    Image(gsl::not_null<IImagePrimitive *> primitive, IImageLoader &loader, boost::uuids::uuid uuid, const Position &pos = {})
        : m_primitive{primitive}, m_imageLoader{loader}
    {
        m_primitive->setPosition(pos);
    }

    void setImage(const std::filesystem::path &path)
    {
        m_imageLoader.load(m_primitive, path);
    }

    virtual bool empty() const override { return m_primitive->empty(); }

    virtual gsl::not_null<IImagePrimitive *> primitive() const override { return m_primitive; }

    Position position() const { return m_primitive->position(); }

    void setPosition(const Position &pos)
    {
        m_primitive->setPosition(pos);
    }

private:
    IImageLoader &m_imageLoader;
    gsl::not_null<IImagePrimitive *> m_primitive;
    // Position m_position;
};

#endif // !_IMAGE_HPP_
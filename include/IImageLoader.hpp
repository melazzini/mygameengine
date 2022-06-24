#ifndef _IIMAGELOADER_HPP_
#define _IIMAGELOADER_HPP_
#include<filesystem>
#include"gsl/gsl"

struct IImagePrimitive;

struct IImageLoader
{
    virtual void load(gsl::not_null<IImagePrimitive *>, const std::filesystem::path &path) const = 0;
};

#endif // _IIMAGELOADER_HPP_

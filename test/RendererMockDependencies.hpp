#ifndef _RENDERERMOCKDEPENDENCIES_HPP_
#define _RENDERERMOCKDEPENDENCIES_HPP_

#include <gmock/gmock.h>
#include "Image.hpp"
#include "ImageLoader.hpp"
#include "Window.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Eq;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::WithArgs;

struct RenderEngineMock : RenderEngine
{
    MOCK_METHOD(void, presentScene, (), (override));
};

struct WindowPrimitiveMock : IWindowPrimitive
{
    MOCK_METHOD(void, clearWithRenderer, (gsl::not_null<IRenderer *> renderer, const Color &color), (override));
};

struct WindowMock : IWindow
{
    MOCK_METHOD(gsl::not_null<IWindowPrimitive *>, primitive, (), (const, override));
};

struct ImageMock : IImage
{
    MOCK_METHOD(bool, empty, (), (const override));
    MOCK_METHOD(gsl::not_null<IImagePrimitive *>, primitive, (), (const, override));
};

struct ImagePrimitiveMock : IImagePrimitive
{
    MOCK_METHOD(void, loadWithRenderer, (gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path), (override));
    MOCK_METHOD(void, paintWithRenderer, (gsl::not_null<IRenderer *> renderer), (override));
    MOCK_METHOD(bool, empty, (), (const, override));
    MOCK_METHOD(void, setPosition, (const Position &), (override));
    MOCK_METHOD(Position, position, (), (const, override));
};

#endif //_RENDERERMOCKDEPENDENCIES_HPP_
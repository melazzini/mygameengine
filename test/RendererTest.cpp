#include <gmock/gmock.h>
#include "Image.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

using testing::_;
using testing::Eq;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::WithArgs;

struct WindowPrimitiveMock : IWindowPrimitive
{
    MOCK_METHOD(void, clearWithRenderer, (gsl::not_null<Renderer *> renderer, const Color &color), (override));
    MOCK_METHOD(void, presentWithRenderer, (gsl::not_null<Renderer *> renderer), (override));
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
};

struct TheRenderer : Test
{
    ImageMock image;
    RenderEngine engine;
    Renderer renderer{&engine};
    WindowMock wnd;
    WindowPrimitiveMock windowPrimitiveMock;
    ImagePrimitiveMock imagePrimitiveMock;
};

TEST_F(TheRenderer, ThrowsWhenAttemptingToRenderAnImageIfItIsEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(true));

    EXPECT_THROW(renderer.render(&image), std::runtime_error);
}

TEST_F(TheRenderer, PassesItSelfToTheImagePrimitiveToRenderItIfTheImageIsNotEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(false));
    EXPECT_CALL(image, primitive()).WillOnce(Return(&imagePrimitiveMock));

    EXPECT_CALL(imagePrimitiveMock, paintWithRenderer(static_cast<gsl::not_null<IRenderer *>>(&renderer)));

    renderer.render(&image);
}

TEST(ARenderer, CanReturnARefToTheRenderEngine)
{
    RenderEngine engine;

    Renderer renderer{&engine};

    ASSERT_THAT(renderer.engine(), Eq(&engine));
}

TEST_F(TheRenderer, ClearsTheWindowUsingThePrimitiveWindow)
{
    EXPECT_CALL(wnd, primitive()).WillOnce(Return(&windowPrimitiveMock));

    EXPECT_CALL(windowPrimitiveMock, clearWithRenderer(static_cast<gsl::not_null<Renderer *>>(&renderer), Color::Black));

    renderer.clearWindow(&wnd, Color::Black);
}

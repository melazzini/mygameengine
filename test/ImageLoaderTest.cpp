#include <gmock/gmock.h>
#include "Image.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::WithArgs;

struct ImagePrimitiveMock : IImagePrimitive
{
    MOCK_METHOD(void, loadWithRenderer, (gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path), (override));
    MOCK_METHOD(void, paintWithRenderer, (gsl::not_null<IRenderer *> renderer), (override));
    MOCK_METHOD(bool, empty, (), (const, override));
};

TEST(AnInstanceOfLoader, DISABLED_IsCreatedWithARenderer)
{
    RenderEngine engine;

    Renderer r{&engine};

    gsl::not_null<Renderer *> renderer{&r};
    ImageLoader loader(renderer);
}

struct ALoader : Test
{
    NiceMock<ImagePrimitiveMock> primitive;
    std::filesystem::path path{"path"};

    // Renderer r;

    RenderEngine engine;

    Renderer r{&engine};

    gsl::not_null<Renderer *> renderer{&r};
    ImageLoader imageLoader{renderer};
};

TEST_F(ALoader, MakesThePrimitiveLoadTheImageItself)
{
    EXPECT_CALL(primitive, loadWithRenderer(static_cast<gsl::not_null<IRenderer *>>(renderer), path));

    imageLoader.load(&primitive, path);
}

TEST_F(ALoader, ThrowsIfThePrimitiveIsEmptyAfterAttemptingToLoadAnImage)
{
    EXPECT_CALL(primitive, loadWithRenderer(static_cast<gsl::not_null<IRenderer *>>(renderer), path));
    EXPECT_CALL(primitive, empty()).WillOnce(Return(true));

    EXPECT_THROW(imageLoader.load(&primitive, path), std::runtime_error);
}
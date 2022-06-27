#include <gmock/gmock.h>
#include "Image.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Eq;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::WithArgs;

struct ImageMock : IImage
{
    MOCK_METHOD(bool, empty, (), (const override));
    MOCK_METHOD(gsl::not_null<IImagePrimitive *>, primitive, (), (const, override));
};

struct ImagePrimitiveMock : IImagePrimitive
{
    MOCK_METHOD(void, loadWithRenderer, (gsl::not_null<Renderer *> renderer, const std::filesystem::path &path), (override));
    MOCK_METHOD(void, paintWithRenderer, (gsl::not_null<Renderer *> renderer), (override));
    MOCK_METHOD(bool, empty, (), (const, override));
};

struct TheRenderer : Test
{
    ImageMock image;
    RenderEngine engine;
    Renderer renderer{&engine};

    ImagePrimitiveMock primitiveMock;
};

TEST_F(TheRenderer, ThrowsWhenAttemptingToRenderAnImageIfItIsEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(true));

    EXPECT_THROW(renderer.render(&image), std::runtime_error);
}

TEST_F(TheRenderer, PassesItSelfToTheImagePrimitiveToRenderItIfTheImageIsNotEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(false));
    EXPECT_CALL(image, primitive()).WillOnce(Return(&primitiveMock));

    EXPECT_CALL(primitiveMock, paintWithRenderer(static_cast<gsl::not_null<Renderer *>>(&renderer)));

    renderer.render(&image);
}

TEST(ARenderer, CanReturnARefToTheRenderEngine)
{
    RenderEngine engine;

    Renderer renderer{&engine};

    ASSERT_THAT(renderer.engine(), Eq(&engine));
}

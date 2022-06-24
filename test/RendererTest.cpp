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
using testing::Eq;

struct ImageMock : IImage
{
    MOCK_METHOD(bool, empty, (), (const override));
    MOCK_METHOD(void, renderPrimitive, (gsl::not_null<Renderer *> renderer), (const override));
};

struct TheRenderer : Test
{
    ImageMock image;
    RenderEngine engine;
    Renderer renderer{&engine};
};

TEST_F(TheRenderer, ThrowsWhenAttemptingToRenderAnImageIfItIsEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(true));

    EXPECT_THROW(renderer.render(&image), std::runtime_error);
}

TEST_F(TheRenderer, PassesItSelfToTheImagePrimitiveToRenderItIfTheImageIsNotEmpty)
{
    EXPECT_CALL(image, empty).WillOnce(Return(false));

    EXPECT_CALL(image, renderPrimitive(static_cast<gsl::not_null<Renderer *>>(&renderer)));

    renderer.render(&image);
}

TEST(ARenderer, CanReturnARefToTheRenderEngine)
{
    RenderEngine engine;

    Renderer renderer{&engine};

    ASSERT_THAT(renderer.engine(), Eq(&engine));
}

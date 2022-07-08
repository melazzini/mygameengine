#include "RendererMockDependencies.hpp"

TEST(ARenderer, CanReturnARefToTheRenderEngine)
{
    RenderEngine engine;

    Renderer renderer{&engine};

    ASSERT_THAT(renderer.engine(), Eq(&engine));
}

struct TheRenderer : Test
{
    ImageMock image;
    RenderEngineMock engine;
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

TEST_F(TheRenderer, ClearsTheWindowUsingThePrimitiveWindow)
{
    EXPECT_CALL(wnd, primitive()).WillOnce(Return(&windowPrimitiveMock));

    EXPECT_CALL(windowPrimitiveMock, clearWithRenderer(static_cast<gsl::not_null<IRenderer *>>(&renderer), Color::Black));

    renderer.clearWindow(&wnd, Color::Black);
}

TEST_F(TheRenderer, PresentsTheCurrentSceneUsingTheEngine)
{
    EXPECT_CALL(engine, presentScene());
    renderer.present();
}

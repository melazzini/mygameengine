#include <gmock/gmock.h>
#include "Window.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::WithArgs;


struct AWindow : Test
{
    RenderEngine engine;
    Renderer renderer{&engine};
    Window wnd;
    Color color{0, 0, 0, 255};
};

TEST_F(AWindow, CanClearItselfUsingTheRendererAndAColor)
{
    wnd.clear(&renderer, color);
}

TEST_F(AWindow, CanPresentItselfWithTheRenderer)
{
    wnd.present(&renderer);
}
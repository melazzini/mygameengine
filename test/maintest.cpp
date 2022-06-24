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

struct Color
{
    int r;
    int g;
    int b;
    int alpha;
};

struct Window
{
    void clear(gsl::not_null<Renderer *> renderer, const Color color)
    {
    }
};

TEST(AWindow, CanClearItselfUsingTheRendererAndAColor)
{
    RenderEngine engine;
    Renderer renderer{&engine};
    Window wnd;
    Color color{0, 0, 0, 255};

    wnd.clear(&renderer, color);
}
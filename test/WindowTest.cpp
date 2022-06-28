#include <gmock/gmock.h>
#include "Window.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;
using testing::Eq;

struct WindowPrimitiveMock : IWindowPrimitive
{
    MOCK_METHOD(void, clearWithRenderer, (gsl::not_null<IRenderer *>, const Color &), (override));
};

TEST(AnInstanceOfWindow, IsCreatedWithAPrimitive)
{
    WindowPrimitiveMock primitive;
    Window wnd{&primitive};
}

TEST(AWindow, CanReturnARefToThePrimitive)
{
    WindowPrimitiveMock primitive;
    Window wnd{&primitive};

    ASSERT_THAT(wnd.primitive(), Eq(&primitive));
}
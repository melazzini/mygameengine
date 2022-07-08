#include <gmock/gmock.h>
#include "Window.hpp"
#include "ImageLoader.hpp"
#include "Renderer.hpp"
#include "Box.hpp"

using testing::_;
using testing::Eq;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;

struct BoxPrimitiveMock : IBoxPrimitive
{
};

struct ABox : Test
{
    BoxPrimitiveMock primitive;
    Position aPosition;
    Size aSize;
    Color aColor;
};

TEST_F(ABox, CanBeCreatedWithPrimitivePositionSizeAndColor)
{
    Box box{&primitive, aPosition, aSize, aColor};
}

TEST_F(ABox, CanReturnARefToItsPrimitive)
{
    Box box{&primitive, aPosition, aSize, aColor};

    ASSERT_THAT(box.primitive(), Eq(&primitive));
}
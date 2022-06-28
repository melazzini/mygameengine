#include <gmock/gmock.h>
#include <iostream>
#include "Image.hpp"
#include "Renderer.hpp"

using testing::_;
using testing::Eq;
using testing::Invoke;
using testing::NiceMock;
using testing::Return;
using testing::Test;

struct ImageLoaderMock : IImageLoader
{
    MOCK_METHOD(void, load, (gsl::not_null<IImagePrimitive *>, const std::filesystem::path &), (const, override));
};

struct ImagePrimitiveMock : IImagePrimitive
{
    MOCK_METHOD(void, loadWithRenderer, (gsl::not_null<IRenderer *> renderer, const std::filesystem::path &path), (override));
    MOCK_METHOD(void, paintWithRenderer, (gsl::not_null<IRenderer *> renderer), (override));
    MOCK_METHOD(bool, empty, (), (const, override));
    MOCK_METHOD(void, setPosition, (const Position &), (override));
    MOCK_METHOD(Position, position, (), (const, override));
};

struct AnImage : Test
{
    NiceMock<ImagePrimitiveMock> primitive;
    NiceMock<ImageLoaderMock> imageLoader;
    std::filesystem::path path{"path"};
    boost::uuids::uuid uuid;
    Position position{};
};

TEST_F(AnImage, IsCreateWithAPrimitiveLoaderAndUuid)
{
    Image(&primitive, imageLoader, uuid);
}

TEST_F(AnImage, IsGivenAPathToSetTheInternalImageUsingTheLoader)
{
    EXPECT_CALL(imageLoader, load(static_cast<gsl::not_null<IImagePrimitive *>>(&primitive), path));

    Image image(&primitive, imageLoader, uuid);
    image.setImage(path);
}

TEST_F(AnImage, IsEmptyIfThePrimitiveIsEmpty)
{
    ON_CALL(primitive, empty()).WillByDefault(Return(true));
    Image image(&primitive, imageLoader, uuid);
    ASSERT_TRUE(primitive.empty());

    ASSERT_TRUE(image.empty());
}

TEST_F(AnImage, IsNotEmptyIfThePrimitiveIsNotEmpty)
{
    ON_CALL(primitive, empty()).WillByDefault(Return(false));
    Image image(&primitive, imageLoader, uuid);
    ASSERT_FALSE(primitive.empty());

    ASSERT_FALSE(image.empty());
}

TEST_F(AnImage, PlacesThePrimitiveAtTheOrigin_00_ByDefault)
{
    Position origin{};

    EXPECT_CALL(primitive, setPosition(origin));

    Image image(&primitive, imageLoader, uuid);
}

TEST_F(AnImage, CanPlaceThePrimitiveAtACertainInitialPosition)
{
    Position pos{1, 1};

    EXPECT_CALL(primitive, setPosition(pos));

    Image image(&primitive, imageLoader, uuid, pos);
}

TEST_F(AnImage, MovesThePrimitiveIfWeChangeItsPositionAccordingly)
{
    Image image(&primitive, imageLoader, uuid, position);

    position = {200, 300};
    EXPECT_CALL(primitive, setPosition(position));

    image.setPosition(position);
}

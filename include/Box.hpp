#ifndef _BOX_HPP_
#define _BOX_HPP_
#include "IBoxPrimitive.hpp"

struct IBox
{
    virtual gsl::not_null<IBoxPrimitive *> primitive() const = 0;
};

struct Box : IBox
{
    Box(gsl::not_null<IBoxPrimitive *> primitive, const Position &, const Size &, const Color &)
        : m_primitive{primitive} {}

    gsl::not_null<IBoxPrimitive *> primitive() const { return m_primitive; }

private:
    gsl::not_null<IBoxPrimitive *> m_primitive;
};

#endif //_BOX_HPP_
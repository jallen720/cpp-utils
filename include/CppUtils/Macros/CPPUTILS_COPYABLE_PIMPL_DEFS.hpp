#pragma once


#define CPPUTILS_COPYABLE_PIMPL_DEFS(OBJECT)\
OBJECT::OBJECT(const OBJECT & original)\
    : impl(new Impl(*original.impl))\
{}\
\
\
OBJECT & OBJECT::operator = (const OBJECT & original)\
{\
    this->impl.reset(new Impl(*original.impl));\
    return *this;\
}

#pragma once


#define JCORE_COPYABLE_PIMPL_DEFS(OBJECT)\
OBJECT::OBJECT(const OBJECT& original)\
    : impl(new Impl(*original.impl)) {}\
\
OBJECT::OBJECT(OBJECT&& original) = default;\
OBJECT::~OBJECT() = default;\
\
OBJECT& OBJECT::operator =(const OBJECT& original) {\
    this->impl.reset(new Impl(*original.impl));\
    return *this;\
}\
\
OBJECT& OBJECT::operator =(OBJECT&& original) = default;

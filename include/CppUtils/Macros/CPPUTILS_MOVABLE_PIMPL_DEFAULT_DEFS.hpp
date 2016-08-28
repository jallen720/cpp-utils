#pragma once


#define CPPUTILS_MOVABLE_PIMPL_DEFAULT_DEFS(OBJECT)\
OBJECT::OBJECT(OBJECT &&) = default;\
OBJECT & OBJECT::operator = (OBJECT &&) = default;

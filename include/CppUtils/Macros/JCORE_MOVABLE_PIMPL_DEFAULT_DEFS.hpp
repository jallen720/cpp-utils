#pragma once


#define JCORE_MOVABLE_PIMPL_DEFAULT_DEFS(OBJECT)\
OBJECT::OBJECT(OBJECT &&) = default;\
OBJECT & OBJECT::operator = (OBJECT &&) = default;

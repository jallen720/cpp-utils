#pragma once


#define JCORE_MOVABLE_PIMPL_DEFS(OBJECT)\
OBJECT::OBJECT(OBJECT&& original) = default;\
OBJECT::~OBJECT() = default;\
OBJECT& OBJECT::operator =(OBJECT&& original) = default;

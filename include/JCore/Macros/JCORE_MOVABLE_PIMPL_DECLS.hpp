#pragma once


#define JCORE_MOVABLE_PIMPL_DECLS(OBJECT)\
OBJECT(const OBJECT& original) = delete;\
OBJECT(OBJECT&& original);\
~OBJECT();\
OBJECT& operator =(const OBJECT& original) = delete;\
OBJECT& operator =(OBJECT&& original);

#pragma once


#define JCORE_MOVABLE_PIMPL_DECLS(OBJECT)\
OBJECT(const OBJECT&) = delete;\
OBJECT(OBJECT&&);\
~OBJECT();\
OBJECT& operator =(const OBJECT&) = delete;\
OBJECT& operator =(OBJECT&&);

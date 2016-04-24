#pragma once


#define JCORE_COPYABLE_PIMPL_DECLS(OBJECT)\
OBJECT(const OBJECT& original);\
OBJECT(OBJECT&&);\
~OBJECT();\
OBJECT& operator =(const OBJECT& original);\
OBJECT& operator =(OBJECT&&);

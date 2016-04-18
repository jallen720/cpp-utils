#pragma once


#define JCORE_PIMPL_COPY_DECLS(OBJECT)\
OBJECT(const OBJECT& original);\
OBJECT(OBJECT&& original);\
~OBJECT();\
OBJECT& operator =(const OBJECT& original);\
OBJECT& operator =(OBJECT&& original);

#pragma once


#define CPPUTILS_MOVABLE_DECLS(OBJECT)\
OBJECT(OBJECT &&);\
OBJECT & operator = (OBJECT &&);

#pragma once


#define CPPUTILS_COPYABLE_DECLS(OBJECT)\
OBJECT(const OBJECT & original);\
OBJECT & operator = (const OBJECT & original);

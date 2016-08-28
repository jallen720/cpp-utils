#pragma once


#define JCORE_MOVABLE_DECLS(OBJECT)\
OBJECT(OBJECT &&);\
OBJECT & operator = (OBJECT &&);

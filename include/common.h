#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"
#include "types.h"

typedef union MoodGraphPoint{
	s16 value;
	struct axis{
		s8 dynamic;
		s8 upper;
	} axis;
} MoodGraphPoint;

#endif
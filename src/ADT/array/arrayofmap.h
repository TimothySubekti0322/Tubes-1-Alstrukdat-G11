#ifndef __ARRAY_MAP_
#define __ARRAY_MAP_

#include "../map/map.h"
#define StartSize 100


typedef struct {
	Map M;
	int Kapasitas;
	int Neff;
} ArrayMap;

#endif
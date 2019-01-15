#ifndef _MAP_DS_H_INCLUDED_
#define _MAP_DS_H_INCLUDED_

#include "tiles_ds.h"

union tile_mask_2u {
	struct {
		tile_2t d;
		tile_2t m;
	} sep;
	tile_mask_2t raw;
};

enum tile_type {
	TILE_TYPE = 0,
	TILE_TYPE2,
	TILE_TYPE2_MASK,
	TILE_TYPE2_WALL_L,
	TILE_TYPE2_WALL_R
};

struct tile_map_node {
	enum tile_type type;
	int *t;
	unsigned char bg, fg;
};
struct tile_map_layer {
	int level;
	struct tile_map_node **tn;
	struct tile_map_node ***tn_list;
};
struct tile_map {
	int w, h, l; /* width, height, levels */
	//struct tile_map_node **tn;
	struct tile_map_layer *layers;
};

struct tile_map map1;

#endif /* _MAP_DS_H_INCLUDED_ */

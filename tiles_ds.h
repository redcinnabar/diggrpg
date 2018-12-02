#ifndef _TILES_DS_H_INCLUDED_
#define _TILES_DS_H_INCLUDED_

#define TILE_SIZE_H	16
#define TILE_SIZE_W	32

typedef int tile_t[TILE_SIZE_H];

tile_t t_mask;
tile_t t1;

#if 0
int t2[32];
int t3[32];
int t4[32];
int t5[32];
int t6[32];

struct tiles_map {
	int *t[8][8];
};
#endif

#endif /* _TILES_DS_H_INCLUDED_ */


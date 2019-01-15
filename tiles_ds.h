#ifndef _TILES_DS_H_INCLUDED_
#define _TILES_DS_H_INCLUDED_

#define TILE_SIZE_H	16
#define TILE_SIZE2_H	32
#define TILE_SIZE3_H	48
#define TILE_SIZE_W	32

typedef int tile_t[TILE_SIZE_H];
typedef int tile_2t[TILE_SIZE2_H];
typedef int tile_mask_2t[TILE_SIZE2_H * 2];

tile_t t_mask;
tile_t t1;
tile_t t2;
tile_t t3;
tile_t t4;
tile_t t5;
tile_t t6;

tile_2t t_mask2;
tile_2t t1_2;

tile_mask_2t tm1_2;
tile_mask_2t tm2_2;

tile_mask_2t wall1_l;
tile_mask_2t wall1_r;

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


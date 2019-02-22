#ifndef _TILES_DS_H_INCLUDED_
#define _TILES_DS_H_INCLUDED_

#define TILE_SIZE_H	16
#define TILE_SIZE2_H	32
#define TILE_SIZE3_H	48
#define TILE_SIZE_W	32

typedef int tile_t[TILE_SIZE_H];
typedef int tile_2t[TILE_SIZE2_H];
typedef int tile_mask_2t[TILE_SIZE2_H * 2];

extern tile_t t_mask;
extern tile_t t1, t2, t3, t4, t5, t6, t7;

extern tile_2t t_mask2;
extern tile_2t t1_2;

extern tile_mask_2t tm1_2;
extern tile_mask_2t tm2_2;

extern tile_mask_2t wall1_l;
extern tile_mask_2t wall1_r;

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


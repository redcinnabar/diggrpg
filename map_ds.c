#include <stddef.h>

#include "map_ds.h"

/***************************************************/
/* First testing map                               */
/***************************************************/

struct tile_map_node
	nl1l1[] = {{0, t4, 1, 2},{0, t4, 4,12},{0, t4, 7, 8},{0, t4, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl2l1[] = {{0, t4, 1, 2},{0, t3, 1, 6},{0, t3, 7, 8},{0, t3, 4,12}, {0, t4, 12,4},{0, t4, 4,12},{0, t4, 4,12} },
	nl3l1[] = {{0, t4, 1, 2},{0, t3, 5, 6},{0, t3, 7, 8},{0, t5, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl4l1[] = {{0, t4, 1, 2},{0, t3, 5, 6},{0, t5, 7, 8},{0, t5, 1, 2}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl5l1[] = {{0, t4, 1, 2},{0, t5, 5, 6},{0, t5, 7, 8},{0, t5, 4,12}, {0, t4, 4,12},{0, t7, 4,12},{0, t4, 4,12} },
	nl6l1[] = {{0, t6, 1, 2},{0, t1, 5, 6},{0, t1, 7, 8},{0, t2, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl7l1[] = {{0, t4, 1, 2},{0, t1, 5, 6},{0, t1, 7, 8},{0, t2, 7, 8}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl8l1[] = {{0, t4, 1, 2},{0, t4, 5, 6},{0, t4, 7, 8},{0, t4, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} };
struct tile_map_node *node_lines_l1[] =
	{ nl1l1, nl2l1, nl3l1, nl4l1, nl5l1, nl6l1, nl7l1, nl8l1 };

struct tile_map_node
	nl1x1l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 3, 4}, {TILE_TYPE2_WALL_R, wall1_r, 4, 5}, {0, }},
	nl1x2l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 5, 6}, {0, }},
	nl1x3l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 6, 7}, {0, }},
	nl1x5l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 7, 8}, {0, }},
	nl1x6l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 8, 9}, {0, }},
	nl1x7l1[] = {{TILE_TYPE2_WALL_L, wall1_l, 9,10}, {0, }},
	nl1x8l1[] = {{TILE_TYPE2_WALL_L, wall1_l,10,11}, {0, }},
	nl5x1l1[] = {{TILE_TYPE2_WALL_R, wall1_r,13,14}, {2, tm2_2, 12, 2}, {0, }},
	nl5x4l1[] = {{1, t1_2, 4, 12}, {0, }},
	nl5x6l1[] = {{2, tm1_2, 1, 14}, {0, }},
	nl6x1l1[] = {{TILE_TYPE2_WALL_R, wall1_r,14,15}, {0, }},
	nl7x1l1[] = {{TILE_TYPE2_WALL_R, wall1_r,16,17}, {0, }};
struct tile_map_node
	*nl_l1l1[] = {nl1x1l1, 0, 0, 0, nl5x1l1, nl6x1l1, nl7x1l1},
	*nl_l2l1[] = {nl1x2l1, 0, 0, 0, 0,       0,       0},
	*nl_l3l1[] = {nl1x3l1, 0, 0, 0, 0,       0,       0},
	*nl_l4l1[] = {0,       0, 0, 0, nl5x4l1, 0,       0},
	*nl_l5l1[] = {nl1x5l1, 0, 0, 0, 0,       0,       0},
	*nl_l6l1[] = {nl1x6l1, 0, 0, 0, nl5x6l1, 0,       0},
	*nl_l7l1[] = {nl1x7l1, 0, 0, 0, 0,       0,       0},
	*nl_l8l1[] = {nl1x8l1, 0, 0, 0, 0,       0,       0};
struct tile_map_node** node_lines_ll1[] =
	{ nl_l1l1, nl_l2l1, nl_l3l1, nl_l4l1, nl_l5l1, nl_l6l1, nl_l7l1, nl_l8l1 };

struct tile_map_layer layers[] = {
	{ 0, node_lines_l1, node_lines_ll1 },
	//{ 0, NULL, node_lines_ll1 },
	//{ 0, node_lines_l2, NULL },
	{ -1, NULL, NULL }
};

struct tile_map map1 = { 7, 8, 1, layers };


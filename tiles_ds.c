#include <stddef.h>

#include "tiles_ds.h"

tile_t t_mask = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011111111000000000000,
	0b00000000001111111111110000000000,
	0b00000000111111111111111100000000,
	0b00000011111111111111111111000000,
	0b00001111111111111111111111110000,
	0b00111111111111111111111111111100,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111100,
	0b00001111111111111111111111110000,
	0b00000011111111111111111111000000,
	0b00000000111111111111111100000000,
	0b00000000001111111111110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};

tile_t t1 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011000011000000000000,
	0b00000000001100010000110000000000,
	0b00000000110000101000001100000000,
	0b00000011000000101000000011000000,
	0b00001100000001000100000000110000,
	0b00110000000001000100000000001100,
	0b11000000000010000010000000000011,
	0b00110000000011111110000000001100,
	0b00001100000100000001000000110000,
	0b00000011000100000001000011000000,
	0b00000000110000000000001100000000,
	0b00000000001100000000110000000000,
	0b00000000000011000011000000000000,
	0b00000000000000111100000000000000
};

tile_t t2 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011000011000000000000,
	0b00000000001100000000110000000000,
	0b00000000110011111000001100000000,
	0b00000011000010000100000011000000,
	0b00001100000010000100000000110000,
	0b00110000000010001000000000001100,
	0b11000000000011111100000000000011,
	0b00110000000010000010000000001100,
	0b00001100000010000010000000110000,
	0b00000011000010000010000011000000,
	0b00000000110011111100001100000000,
	0b00000000001100000000110000000000,
	0b00000000000011000011000000000000,
	0b00000000000000111100000000000000
};

tile_t t3 = {
	0b00000000000000000000000000000000,
	0b00000000000000110000000000000000,
	0b00000000000011000000000000000000,
	0b00000000001100000000000000000000,
	0b00000000110000000000000000000000,
	0b00000011001100000000001100000000,
	0b00001100000011000000110000000000,
	0b00110000000000110011000000000000,
	0b11000000000000001100000000000000,
	0b00110000000000110011000000000000,
	0b00001100000011000000110000000000,
	0b00000011001100000000001100000000,
	0b00000000110000000000000000000000,
	0b00000000001100000000000000000000,
	0b00000000000011000000000000000000,
	0b00000000000000110000000000000000
};

tile_t t4 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011111111000000000000,
	0b00000000001111111111110000000000,
	0b00000000111111111111111100000000,
	0b00000011111111111111111111000000,
	0b00001111111111111111111111110000,
	0b00111111111111111111111111111100,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111100,
	0b00001111111111111111111111110000,
	0b00000011111111111111111111000000,
	0b00000000111111111111111100000000,
	0b00000000001111111111110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};

tile_t t5 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011110111000000000000,
	0b00000000001111110111110000000000,
	0b00000000111111110111111100000000,
	0b00000011111111110111111111000000,
	0b00001111111111110111111111110000,
	0b00111111111111110111111111111100,
	0b11000000000000000000000000000011,
	0b00111111111111110111111111111100,
	0b00001111111111110111111111110000,
	0b00000011111111110111111111000000,
	0b00000000111111110111111100000000,
	0b00000000001111110111110000000000,
	0b00000000000011110111000000000000,
	0b00000000000000111100000000000000
};

tile_t t6 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011111111000000000000,
	0b00000000001100000000110000000000,
	0b00000000100011111111000000000000,
	0b00000010011111111111111100000000,
	0b00001101111111111111111111010000,
	0b00111011111111111111111111101100,
	0b11111011111111111111111111101111,
	0b00111011111111111111111111101100,
	0b00001101111111111111111111010000,
	0b00000010111111111111111100000000,
	0b00000000000011111111000000000000,
	0b00000000001100000000110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};


tile_2t t_mask2 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011111111000000000000,
	0b00000000001111111111110000000000,
	0b00000000111111111111111100000000,
	0b00000011111111111111111111000000,
	0b00001111111111111111111111110000,
	0b00111111111111111111111111111100,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111100,
	0b00001111111111111111111111110000,
	0b00000011111111111111111111000000,
	0b00000000111111111111111100000000,
	0b00000000001111111111110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};

tile_2t t1_2 = {
	0b00000000000000000000000000000000,
	0b00000000000000111100000000000000,
	0b00000000000011010111000000000000,
	0b00000000001101010101110000000000,
	0b00000000111010101010101100000000,
	0b00000011010101010101010111000000,
	0b00001110101010101010101010110000,
	0b00110101010101010101010101011100,
	0b11101010101010101010101010101111,
	0b11011101010101010101010101011011,
	0b11000110101010101010101011100011,
	0b11010001101010101010101110000011,
	0b11000100011101010101011000000011,
	0b11010001000110101011100000000011,
	0b11000100010001110110000000000011,
	0b11010001000100011000000000000011,
	0b11000100010001010000000000000011,
	0b11010001000100010000000000000011,
	0b11000100010001010000000000000011,
	0b11010001000100010000000000000011,
	0b11000100010001010000000000000011,
	0b11010001000100010000000000000011,
	0b11000100010001010000000000000011,
	0b11010001000100010000000000000011,
	0b11100100010001010000000000001111,
	0b00111001000100010000000000111100,
	0b00001110010001010000000011110000,
	0b00000011100100010000001111000000,
	0b00000000111001010000111100000000,
	0b00000000001110010011110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};



tile_mask_2t tm1_2 = {
	0b00000000000000000000000000000000,
	0b00000000000000011000000000000000,
	0b00000000000001101110000000000000,
	0b00000000000111010101100000000000,
	0b00000000011010101010111000000000,
	0b00000001110101010101010110000000,
	0b00000110101010101010101011100000,
	0b00011101010101010101010101011000,
	0b01101010101010101010101010101110,
	0b01011101010101010101010101011010,
	0b01000110101010101010101011100010,
	0b01010001101010101010101110000010,
	0b01000100011101010101011000000010,
	0b01010001000110101011100000000010,
	0b01000100010001110110000000000010,
	0b01010001000100011000000000000010,
	0b01000100010001010000000000000010,
	0b01010001000100010000000000000010,
	0b01000100010001010000000000000010,
	0b01010001000100010000000000000010,
	0b01000100010001010000000000000010,
	0b01010001000100010000000000000010,
	0b01000100010001010000000000000010,
	0b01010001000100010000000000000010,
	0b11100100010001010000000000001111,
	0b00111001000100010000000000111100,
	0b00001110010001010000000011110000,
	0b00000011100100010000001111000000,
	0b00000000111001010000111100000000,
	0b00000000001110010011110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000,

	0b00000000000000000000000000000000,
	0b00000000000000011000000000000000,
	0b00000000000001111110000000000000,
	0b00000000000111111111100000000000,
	0b00000000011111111111111000000000,
	0b00000001111111111111111110000000,
	0b00000111111111111111111111100000,
	0b00011111111111111111111111111000,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111100,
	0b00001111111111111111111111110000,
	0b00000011111111111111111111000000,
	0b00000000111111111111111100000000,
	0b00000000001111111111110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};

tile_mask_2t tm2_2 = {
	0b00000000000000000000000000000000,
	0b00000000000000011000000000000000,
	0b00000000000001100110000000000000,
	0b00000000000110000001100000000000,
	0b00000000011000000000011000000000,
	0b00000001100000000000000110000000,
	0b00000110000000000000000001100000,
	0b00011000000000000000000000011000,
	0b01100000000000000000000000001110,
	0b01011000000000000000000000011010,
	0b01000110000000000000000001100010,
	0b01000001100000000000000110000010,
	0b01000000011000000000011000000010,
	0b01000000000110000001100000000010,
	0b01000000000001100110000000000010,
	0b01000000000000011000000000000010,
	0b01000000000000010000000000000010,
	0b01000000000000011000000000000010,
	0b01000000000001110110000000000010,
	0b01000000000110010001100000000010,
	0b01000000011000010000011000000010,
	0b01000001100000010000000110000010,
	0b01000110000000010000000001100010,
	0b01011000000000010000000000011010,
	0b11100000000000010000000000001111,
	0b00111000000000010000000000111100,
	0b00001110000000010000000011110000,
	0b00000011100000010000001111000000,
	0b00000000111000010000111100000000,
	0b00000000001110010011110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000,

	0b00000000000000000000000000000000,
	0b00000000000000011000000000000000,
	0b00000000000001111110000000000000,
	0b00000000000111100111100000000000,
	0b00000000011110000001111000000000,
	0b00000001111000000000011110000000,
	0b00000111100000000000000111100000,
	0b00011110000000000000000001111000,
	0b01111000000000000000000000011110,
	0b01111110000000000000000001111110,
	0b01111111100000000000000111111110,
	0b01100111111000000000011111100110,
	0b01100001111110000001111110000110,
	0b01100000011111100111111000000110,
	0b01100000000111111111100000000110,
	0b01100000000001111110000000000110,
	0b01100000000000111000000000000110,
	0b01100000000001111110000000000110,
	0b01100000000111111111100000000110,
	0b01100000011111111111111000000110,
	0b01100001111111111111111110000110,
	0b01100111111111111111111111100110,
	0b01111111111111111111111111111110,
	0b01111111111111111111111111111110,
	0b11111111111111111111111111111111,
	0b00111111111111111111111111111100,
	0b00001111111111111111111111110000,
	0b00000011111111111111111111000000,
	0b00000000111111111111111100000000,
	0b00000000001111111111110000000000,
	0b00000000000011111111000000000000,
	0b00000000000000111100000000000000
};


tile_mask_2t wall1_l = {
	0b00000000000000000000000000000000,
	0b00000000000000110000000000000000,
	0b00000000000011110000000000000000,
	0b00000000001111110000000000000000,
	0b00000000111111110000000000000000,
	0b00000011111111110000000000000000,
	0b00001111111111110000000000000000,
	0b00111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111000000000000000000,
	0b11111111111100000000000000000000,
	0b11111111110000000000000000000000,
	0b11111111000000000000000000000000,
	0b11111100000000000000000000000000,
	0b11110000000000000000000000000000,
	0b11000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,

	0b00000000000000000000000000000000,
	0b00000000000000110000000000000000,
	0b00000000000011110000000000000000,
	0b00000000001111110000000000000000,
	0b00000000111111110000000000000000,
	0b00000011111111110000000000000000,
	0b00001111111111110000000000000000,
	0b00111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111110000000000000000,
	0b11111111111111000000000000000000,
	0b11111111111100000000000000000000,
	0b11111111110000000000000000000000,
	0b11111111000000000000000000000000,
	0b11111100000000000000000000000000,
	0b11110000000000000000000000000000,
	0b11000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000
};

tile_mask_2t wall1_r = {
	0b00000000000000000000000000000000,
	0b00000000000000001100000000000000,
	0b00000000000000001111000000000000,
	0b00000000000000001111110000000000,
	0b00000000000000001111111100000000,
	0b00000000000000001111111111000000,
	0b00000000000000001111111111110000,
	0b00000000000000001111111111111100,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000000011111111111111,
	0b00000000000000000000111111111111,
	0b00000000000000000000001111111111,
	0b00000000000000000000000011111111,
	0b00000000000000000000000000111111,
	0b00000000000000000000000000001111,
	0b00000000000000000000000000000011,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,

	0b00000000000000000000000000000000,
	0b00000000000000001100000000000000,
	0b00000000000000001111000000000000,
	0b00000000000000001111110000000000,
	0b00000000000000001111111100000000,
	0b00000000000000001111111111000000,
	0b00000000000000001111111111110000,
	0b00000000000000001111111111111100,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000001111111111111111,
	0b00000000000000000011111111111111,
	0b00000000000000000000111111111111,
	0b00000000000000000000001111111111,
	0b00000000000000000000000011111111,
	0b00000000000000000000000000111111,
	0b00000000000000000000000000001111,
	0b00000000000000000000000000000011,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000
};


struct tile_map_node
	nl1l1[] = {{0, t4, 1, 2},{0, t4, 4,12},{0, t4, 7, 8},{0, t4, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl2l1[] = {{0, t4, 1, 2},{0, t3, 1, 6},{0, t3, 7, 8},{0, t3, 4,12}, {0, t4, 12,4},{0, t4, 4,12},{0, t4, 4,12} },
	nl3l1[] = {{0, t4, 1, 2},{0, t3, 5, 6},{0, t3, 7, 8},{0, t5, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl4l1[] = {{0, t4, 1, 2},{0, t3, 5, 6},{0, t5, 7, 8},{0, t5, 1, 2}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl5l1[] = {{0, t4, 1, 2},{0, t5, 5, 6},{0, t5, 7, 8},{0, t5, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl6l1[] = {{0, t4, 1, 2},{0, t1, 5, 6},{0, t1, 7, 8},{0, t2, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl7l1[] = {{0, t4, 1, 2},{0, t1, 5, 6},{0, t1, 7, 8},{0, t2, 7, 8}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} },
	nl8l1[] = {{0, t4, 1, 2},{0, t4, 5, 6},{0, t4, 7, 8},{0, t4, 4,12}, {0, t4, 4,12},{0, t4, 4,12},{0, t4, 4,12} };
struct tile_map_node *node_lines_l1[] =
	{ nl1l1, nl2l1, nl3l1, nl4l1, nl5l1, nl6l1, nl7l1, nl8l1 };

#if 0
struct tile_map_node
	nl1l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{2,tm2_2,12,2},{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl2l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl3l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl4l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {1,t1_2,4,12},{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl5l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl6l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{2,tm1_2,1,14},{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl7l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 } },
	nl8l2[] = {{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 }, {0, 0, 0, 0 },{0, 0, 0, 0 },{0, 0, 0, 0 } };
struct tile_map_node *node_lines_l2[] =
	{ nl1l2, nl2l2, nl3l2, nl4l2, nl5l2, nl6l2, nl7l2, nl8l2 };
#endif
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


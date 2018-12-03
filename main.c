#include <stdio.h>

#include <allegro.h>

#include "tiles_ds.h"


void print_tile(tile_t *t)
{
	int i, j;
	for (i = 0; i < TILE_SIZE_H; ++i) {
		for (j = 0; j < TILE_SIZE_W; ++j) {
			if ((*t)[i] & (1 << j))
				putchar('1');
			else
				putchar('0');
		}
		putchar('\n');
	}
}

BITMAP *load_tile_bitmap(tile_t *t, unsigned char fg, unsigned char bg)
{
	BITMAP *image;
	int i, j;
	unsigned char *line;
	int cur_t, cur_t_mask;
	int bit_mask;
	image = create_bitmap_ex(8, TILE_SIZE_W, TILE_SIZE_H);
	for (i = 0; i < TILE_SIZE_H; ++i) {
		line = image->line[i];
		cur_t = (*t)[i];
		cur_t_mask = t_mask[i];
		for (j = TILE_SIZE_W - 1; j >= 0; --j) {
			bit_mask = 1 << j;
			if (cur_t_mask & bit_mask) {
				if (cur_t & (1 << j))
					*line = fg;
				else
					*line = bg;
			} else {
				*line = 0; /* TRANSPARENT */
			}
			++line;
		}
	}
	return image;
}

int main(int argc, char *argv[])
{
	BITMAP *image_t1;
	BITMAP *image_t2;
	BITMAP *image_t3;
	BITMAP *image_t4;
	BITMAP *image_t5;
	BITMAP *image_t6;

	int gfx_mode = GFX_AUTODETECT;
	int resx = 800;
	int resy = 600;
	if (argc == 2 && strcmp(argv[1], "-w") == 0) {
		gfx_mode = GFX_AUTODETECT_WINDOWED;
	} else if (argc == 2 && strcmp(argv[1], "-s") == 0) {
		resx = 640;
		resy = 480;
	}

	/* initialise everything */
	if (allegro_init() != 0) {
		printf("allegro_init(): error; check library path\n");
		return 1;
	}
	install_keyboard(); 
	install_mouse();
	install_timer();

	set_color_depth(8);
	if (set_gfx_mode(gfx_mode, resx, resy, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n",
					allegro_error);
			return 1;
		}
	}

	image_t1 = load_tile_bitmap(&t1, 3, 11);
	image_t2 = load_tile_bitmap(&t2, 4, 12);
	image_t3 = load_tile_bitmap(&t3, 1, 2);
	image_t4 = load_tile_bitmap(&t4, 5, 6);
	image_t5 = load_tile_bitmap(&t5, 7, 8);
	image_t6 = load_tile_bitmap(&t6, 9, 13);

	masked_blit(image_t1, screen, 0, 0, (SCREEN_W-image_t1->w)/2,
		(SCREEN_H-image_t1->h)/2, image_t1->w, image_t1->h);

	masked_blit(image_t2, screen, 0, 0, 0, 0, image_t2->w, image_t2->h);
	masked_blit(image_t3, screen, 0, 0, TILE_SIZE_W, 0,
			image_t3->w, image_t3->h);
	masked_blit(image_t4, screen, 0, 0, TILE_SIZE_W / 2, TILE_SIZE_H / 2,
			image_t4->w, image_t4->h);
	masked_blit(image_t5, screen, 0, 0,
			TILE_SIZE_W / 2 + TILE_SIZE_W, TILE_SIZE_H / 2,
			image_t5->w, image_t5->h);
	masked_blit(image_t6, screen, 0, 0, TILE_SIZE_W, TILE_SIZE_H,
			image_t6->w, image_t6->h);
	
	readkey();


	destroy_bitmap(image_t6);
	destroy_bitmap(image_t5);
	destroy_bitmap(image_t4);
	destroy_bitmap(image_t3);
	destroy_bitmap(image_t2);
	destroy_bitmap(image_t1);

	set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	printf("Hello, iso, attempt #3, tst: %d\n", 0b0011);

	print_tile(&t1);

	return 0;
}
END_OF_MAIN()

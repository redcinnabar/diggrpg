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
		for (j = 0; j < TILE_SIZE_W; ++j) {
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
	BITMAP *image;

	/* initialise everything */
	if (allegro_init() != 0) {
		printf("allegro_init(): error; check library path\n");
		return 1;
	}
	install_keyboard(); 
	install_mouse();
	install_timer();

	set_color_depth(8);
	if (set_gfx_mode(GFX_AUTODETECT, 800, 600, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
			return 1;
		}
	}

	image = load_tile_bitmap(&t1, 3, 11);
	blit(image, screen, 0, 0, (SCREEN_W-image->w)/2,
		(SCREEN_H-image->h)/2, image->w, image->h);
	
	readkey();
	destroy_bitmap(image);

	set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	printf("Hello, iso, attempt #3, tst: %d\n", 0b0011);

	print_tile(&t1);

	return 0;
}
END_OF_MAIN()

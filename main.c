#include <stdio.h>

#include <allegro.h>

#include "map_ds.h"
#include "map_m_ds.h"
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
		for (j = TILE_SIZE_W - 1; j >= 0; --j, ++line) {
			bit_mask = 1 << j;
			if (cur_t_mask & bit_mask) {
				if (cur_t & bit_mask)
					*line = fg;
				else
					*line = bg;
			} else {
				*line = 0; /* TRANSPARENT */
			}
		}
	}
	return image;
}

/* blit tile into BITMAP */
void blit_tile(BITMAP *sbuf, enum tile_type type, int *t, int sx, int sy,
				unsigned char fg, unsigned char bg)
{
	int i, j;
	unsigned char *line;
	int *cur_t, *cur_t_mask;
	int bit_mask;
	int sy_off = 0;
	int rsy, rsx; /* real start y, start x */
	union tile_mask_2u *conv_2u;
	int ex, ey;

	if (sx >= sbuf->w)
		return;

	/* get offset for high tiles */
	cur_t = t;
	switch (type) {
	case TILE_TYPE2:
		sy_off = TILE_SIZE_H;
		cur_t_mask = t_mask2;
		break;
	case TILE_TYPE2_WALL_L:
	case TILE_TYPE2_WALL_R:
	case TILE_TYPE2_MASK:
		sy_off = TILE_SIZE_H;
		conv_2u = (union tile_mask_2u*)t;
		cur_t_mask = conv_2u->sep.m;
		break;
	default:
		cur_t_mask = t_mask;
		break;
	}

	/* calculate visible part limits */
	rsy = sy - sy_off;
	if (rsy < 0) {
		cur_t -= rsy;
		cur_t_mask -= rsy;
		rsy = 0;
	}

	if (rsy > sbuf->h)
		return;

	rsx = sx;
	if (rsx < 0)
		rsx = 0;

	ey = TILE_SIZE_H + sy;
	if (ey > sbuf->h)
		ey = sbuf->h;
	ex = sx + TILE_SIZE_W;
	if (ex > sbuf->w)
		ex = sbuf->w;

	/* draw with limit on visible parts */
	for (i = rsy; i < ey; ++i) {
		line = sbuf->line[i] + rsx;
		for (j = TILE_SIZE_W - 1 - (rsx - sx);
				j >= sx + TILE_SIZE_W - ex;
				--j, ++line) {
			bit_mask = 1 << j; //TODO: LSB?
			if (*cur_t_mask & bit_mask) {
				if (*cur_t & bit_mask)
					*line = fg;
				else
					*line = bg;
			}
		}
		++cur_t;
		++cur_t_mask;
	}
}

void blit_tile_map(BITMAP *sbuf, struct tile_map *map, int xo, int yo)
{
	int i, j, k;
	int sx, sy;
	struct tile_map_node *cnode;
	struct tile_map_layer *cur_layer;
	int level;
	cur_layer = map->layers;
	while (cur_layer->level >= 0) {
		//cur_layer = &(map->layers[k]);
		level = cur_layer->level;
		for (j = 0; j < map->h; ++j) {
			for (i = 0; i < map->w; ++i) {
				// TODO: optimize
				sx = xo + (map->h - 1 + i - j)
					* (TILE_SIZE_W >> 1);
				sy = yo + (i + j) * (TILE_SIZE_H >> 1)
					+ TILE_SIZE_H * (map->l - level);
				//printf("DEBUG: sx: %d; sy: %d\n", sx, sy);
				/* skip invisible tiles rendering */
				if ((sx + TILE_SIZE_W) <= 0 && (sy + TILE_SIZE_H) <= 0)
					continue;
				/* single tile node, generally floor */
				if (cur_layer->tn) {
					cnode = &(cur_layer->tn[j][i]);
					if (cnode->t)
						blit_tile(sbuf, cnode->type,
							cnode->t, sx, sy,
							cnode->fg, cnode->bg);
				}
				/* tile node zero-ended list */
				if (cur_layer->tn_list) {
					cnode = cur_layer->tn_list[j][i];
					while (cnode && cnode->t) {
						blit_tile(sbuf, cnode->type,
							cnode->t, sx, sy,
							cnode->fg, cnode->bg);
						++cnode;
					}
				}
			}
		}
		//return;
		++cur_layer;
	}
}


int profile_blit_tile_map()
{
	BITMAP *sbuf = create_bitmap_ex(8, SCREEN_W, SCREEN_H);
	int xoff = 0;
	int yoff = 0;

	for (xoff = -500; xoff < 0; ++xoff) {
		clear_bitmap(sbuf);

		init_metro_map();
		blit_tile_map(sbuf, &metro_map, -150 + xoff, -150 + yoff);
		blit(sbuf, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	}
	destroy_bitmap(sbuf);
}


void app_main_loop()
{
	int key;
	int is_quit = 0;
	BITMAP *sbuf = create_bitmap_ex(8, SCREEN_W, SCREEN_H);
	int xoff = 0;
	int yoff = 0;

	while(!is_quit) {
		clear_bitmap(sbuf);

		init_metro_map();
		blit_tile_map(sbuf, &metro_map, -150 + xoff, -150 + yoff);
		blit(sbuf, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

		key = readkey();
		if ((key & 0xff) == 'q')
			is_quit = 1;
		else {
			switch (key >> 8) {
			case KEY_RIGHT:
				xoff += 1;
				break;
			case KEY_LEFT:
				xoff -= 1;
				break;
			case KEY_UP:
				yoff -= 1;
				break;
			case KEY_DOWN:
				yoff += 1;
				break;
			case KEY_ESC:
				is_quit = 1;
				break;
			}
		}
	}

	destroy_bitmap(sbuf);
}


char *map_name_test1 = "test1";
char *map_name_metro = "metro";
char *map_name_list[] = {"test1", "metro", NULL};

enum cmd_resolution {
	CMD_RESOLUTION_800_600,
	CMD_RESOLUTION_640_480,
	CMD_RESOLUTION_320_200
};
struct cmd_args {
	int is_windowed;
	enum cmd_resolution res;
	char *map_name;
};

int main(int argc, char *argv[])
{
	/*BITMAP *image_t1;
	BITMAP *image_t2;
	BITMAP *image_t3;
	BITMAP *image_t4;
	BITMAP *image_t5;
	BITMAP *image_t6;*/

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

	/* start main loop */
	//profile_blit_tile_map();
	app_main_loop();

	/* many old code to be removed when all will work */
	/*BITMAP *sbuf = create_bitmap_ex(8, SCREEN_W, SCREEN_H);
	clear_bitmap(sbuf);

	//blit_tile_map(sbuf, &map1, 50, 100);
	init_metro_map();
	blit_tile_map(sbuf, &metro_map, -150, -150);
	blit(sbuf, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);*/

	/*image_t1 = load_tile_bitmap(&t1, 3, 11);
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
			image_t6->w, image_t6->h);*/
	
	//readkey();


	/*destroy_bitmap(image_t6);
	destroy_bitmap(image_t5);
	destroy_bitmap(image_t4);
	destroy_bitmap(image_t3);
	destroy_bitmap(image_t2);
	destroy_bitmap(image_t1);*/

	/*destroy_bitmap(sbuf);*/

	set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	/*printf("Hello, iso, attempt #3, tst: %d\n", 0b0011);

	print_tile(&t1);*/

	return 0;
}
END_OF_MAIN()

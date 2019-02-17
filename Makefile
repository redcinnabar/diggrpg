CC=gcc
PROGRAM=iso3prg
CFLAGS=-O2 -std=c99 `allegro-config --cflags`
LIBS=`allegro-config --libs`

OBJ=main.o tiles_ds.o map_ds.o map_m_ds.o

$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.c tiles_ds.h map_ds.h
	$(CC) $(CFLAGS) -c $< -o $@

map_ds.o: map_ds.c map_ds.h tiles_ds.h
	$(CC) $(CFLAGS) -c $< -o $@

map_m_ds.o: map_m_ds.c map_m_ds.h map_ds.h tiles_ds.h
	$(CC) $(CFLAGS) -c $< -o $@

tiles_ds.o: tiles_ds.c tiles_ds.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJ)

all: clean $(PROGRAM)

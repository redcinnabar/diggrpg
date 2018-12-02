CC=gcc
PROGRAM=iso3prg
CFLAGS=-O2 -std=c99 `allegro-config --cflags`
LIBS=`allegro-config --libs`

OBJ=main.o tiles_ds.o

$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

tiles_ds.o: tiles_ds.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJ)

all: clean $(PROGRAM)

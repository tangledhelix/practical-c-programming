CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

sqr: sqr.c
	$(CC) $(CFLAGS) -o sqr sqr.c

clean:
	rm -f sqr

preview:
	$(CC) -E sqr.c


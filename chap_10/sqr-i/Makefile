CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

sqr-i: sqr-i.c
	$(CC) $(CFLAGS) -o sqr-i sqr-i.c

clean:
	rm -f sqr-i

preview:
	$(CC) -E sqr-i.c


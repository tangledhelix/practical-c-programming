CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

max: max.c
	$(CC) $(CFLAGS) -o max max.c

clean:
	rm -f max

preview:
	$(CC) -E max.c


CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

first: first.c
	$(CC) $(CFLAGS) -o first first.c

clean:
	rm -f first

preview:
	$(CC) -E first.c


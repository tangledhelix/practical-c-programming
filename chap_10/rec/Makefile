CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

rec: rec.c
	$(CC) $(CFLAGS) -o rec rec.c

clean:
	rm -f rec

preview:
	$(CC) -E rec.c


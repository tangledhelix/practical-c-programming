CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

all: a2b b2a

a2b: a2b.c
	$(CC) $(CFLAGS) -o a2b a2b.c

b2a: b2a.c
	$(CC) $(CFLAGS) -o b2a b2a.c

clean:
	rm -f a2b b2a

